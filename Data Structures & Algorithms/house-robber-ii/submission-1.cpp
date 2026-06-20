class Solution {
public:
    int rob(vector<int>& nums) {
        size_t N = nums.size();
        vector<int> dp0(N, 0);
        vector<int> dp1(N, 0);

        if (nums.size() == 1) {
            return nums[0];
        }

        dp0[0] = nums[0];
        dp0[1] = std::max(nums[0], nums[1]);

        dp1[1] = nums[1];
        dp1[2] = std::max(nums[1], nums[2]);

        for (size_t i = 2; i < N - 1; ++i)
        {
            dp0[i] = max(dp0[i-1], nums[i] + dp0[i-2]);
        }

        for (size_t i = 3; i < N; ++i)
        {
            dp1[i] = max(dp1[i-1], nums[i] + dp1[i-2]);
        }
        return max(dp0[N-2], dp1[N-1]);
    }
};
