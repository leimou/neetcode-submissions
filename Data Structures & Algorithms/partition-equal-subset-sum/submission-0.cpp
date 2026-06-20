class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;

        vector dp(nums.size() + 1, vector(sum + 1, 0));
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j >= nums[i-1]) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]] + nums[i-1]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][sum] == sum;
    }
};
