class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<int>& coins, int idx, int amount) {

        // Amount complete
        if (amount == 0)
            return 1;

        // Coins khatam
        if (idx == coins.size())
            return 0;

        // Already calculated
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = 0;

        // Take current coin
        if (coins[idx] <= amount) {
            take = f(coins, idx, amount - coins[idx]);
        }

        // Skip current coin
        int skip = f(coins, idx + 1, amount);

        return dp[idx][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        dp.assign(n, vector<int>(amount + 1, -1));

        return f(coins, 0, amount);
    }
};