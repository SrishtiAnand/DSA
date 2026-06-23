class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> arr(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }

            if (!st.empty())
                arr[i] = st.top() - i;  
            else
                arr[i] = 0;

            st.push(i);
        }

        return arr;
    }
};