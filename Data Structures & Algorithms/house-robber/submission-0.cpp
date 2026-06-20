class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];

        for (size_t i = 2; i < nums.size() + 1; ++i) {
            dp[i] = std::max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        return dp[nums.size()];
    }
};
