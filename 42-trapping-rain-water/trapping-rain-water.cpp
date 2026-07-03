class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        vector<int> nxtGrtEl(n);
        vector<int> prevGrtEl(n);
        stack<int> stk;

        // Next Greater Element
        for (int i = 0; i < n; i++) {
            nxtGrtEl[i] = i;

            while (!stk.empty() && h[stk.top()] < h[i]) {
                nxtGrtEl[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        // Previous Greater Element
        for (int i = n - 1; i >= 0; i--) {
            prevGrtEl[i] = i;

            while (!stk.empty() && h[i] > h[stk.top()]) {
                prevGrtEl[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        int leftTip = 0, rightTip = n - 1;
        int ans = 0;

        // Left to right
        for (int i = 0; i < n; i++) {
            if (nxtGrtEl[i] != i) {

                for (int j = i; j < nxtGrtEl[i]; j++) {
                    ans += (h[i] - h[j]);
                }

                i = nxtGrtEl[i] - 1;
            } else {
                leftTip = i;
                break;
            }
        }

        // Right to left
        for (int i = n - 1; i >= 0; i--) {
            if (prevGrtEl[i] != i) {

                for (int j = i; j > prevGrtEl[i]; j--) {
                    ans += (h[i] - h[j]);
                }

                i = prevGrtEl[i] + 1;
            } else {
                rightTip = i;
                break;
            }
        }

        // Middle section
        for (int i = leftTip; i <= rightTip; i++) {
            ans += (h[leftTip] - h[i]);
        }

        return ans;
    }
};