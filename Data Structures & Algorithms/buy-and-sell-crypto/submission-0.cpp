class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][j]: maximum profilt buy at day i, sell at day j.
        // dp[i][j]: 0 (i >= j)
        // dp[0][1] = p[1] - p[0];
        // dp[0][2] = max(dp[0][1], p[2] - p[0])
        // dp[0][3] = max(dp[0][2], p[3] - p[0])
        // dp[1][2] = p[2] - p[1];
        // dp[i][j] = max(d[i][j-1], p[j] - p[i]);

        vector<vector<int>> dp(prices.size(), vector<int>(prices.size(), 0));

        int result = 0;
        for (int i = 0; i < static_cast<int>(prices.size()); ++i)
        {
            for (int j = i + 1; j < static_cast<int>(prices.size()); ++j)
            {
                dp[i][j] = std::max(dp[i][j-1], prices[j] - prices[i]);
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
