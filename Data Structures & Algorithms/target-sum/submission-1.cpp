class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // left - right = target;
        // left + rigth = sum
        // 2l = target + sum;
        // l = (target + sum) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0) {
            return false;
        }
        target = (sum + target) / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
