class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> points(mx + 1, 0);

        
        for (int num : nums) {
            points[num] += num;
        }

        int n = points.size();

        if (n == 1) return points[0];

        vector<int> dp(n);

        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for (int i = 2; i < n; i++) {

            int take = points[i] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(take, skip);
        }

        return dp[n - 1];
    }
};