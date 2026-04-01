class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<long long> st(nums.begin(), nums.end());
        
        int ans = -1;

        for (int num : nums) {
            int count = 0;
            long long curr = num;

            while (st.find(curr) != st.end()) {
                count++;
                curr = curr * curr;
            }

            if (count >= 2) {
                ans = max(ans, count);
            }
        }

        return ans;
    }
};