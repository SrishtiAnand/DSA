class Solution {
public:
    vector<int> dp;

    int f(vector<int>& nums, int i, int end) {
        if (i > end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int rob = nums[i] + f(nums, i + 2, end);
        int skip = f(nums, i + 1, end);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        
        dp.assign(n, -1);
        int ans1 = f(nums, 0, n - 2);

       
        dp.assign(n, -1);
        int ans2 = f(nums, 1, n - 1);

        return max(ans1, ans2);
    }
};