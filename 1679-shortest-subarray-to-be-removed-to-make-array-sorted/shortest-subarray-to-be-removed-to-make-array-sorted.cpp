class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;

        // Increasing prefix
        for (int i = 0; i < n; i++) {
            if (!st.empty() && arr[st.top()] > arr[i])
                break;

            st.push(i);
        }

        int left = st.empty() ? -1 : st.top();

        // Already sorted
        if (left == n - 1)
            return 0;

        // Increasing suffix
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            if (!st.empty() && arr[i] > arr[st.top()])
                break;

            st.push(i);
        }

        int right = st.top();

        // Remove suffix
        int ans = n - left - 1;

        // Remove prefix
        ans = min(ans, right);

        // Try connecting prefix and suffix
        vector<int> prefix;

        while (!st.empty()) {
            prefix.push_back(st.top());
            st.pop();
        }

        reverse(prefix.begin(), prefix.end());

        int j = right;

        for (int i = 0; i <= left; i++) {

            while (j < n && arr[j] < arr[i]) {
                j++;
            }

            if (j == n)
                break;

            ans = min(ans, j - i - 1);
        }

        return ans;
    }
};