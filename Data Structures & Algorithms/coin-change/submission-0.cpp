class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector dp(coins.size() + 1, vector<int>(amount + 1, amount + 1));
        dp[0][0] = 0;

        for (int i = 1; i <= coins.size(); ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coins[i-1]) {
                    dp[i][j] = min(dp[i-1][j], dp[i][j - coins[i-1]] + 1);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if (dp[coins.size()][amount] == amount + 1) {
            return -1;
        }
        return dp[coins.size()][amount];
    }
};
