class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<int>& coins, int idx, int amount) {

        if (amount == 0)
            return 0;

        if (idx == coins.size())
            return 1e9;   

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = 1e9;

        if (coins[idx] <= amount)
            take = 1 + f(coins, idx, amount - coins[idx]);

       
        int skip = f(coins, idx + 1, amount);

        return dp[idx][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = f(coins, 0, amount);

        return (ans >= 1e9) ? -1 : ans;
    }
};