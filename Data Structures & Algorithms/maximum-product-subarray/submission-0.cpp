class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp_max(nums.size(), INT_MIN);
        vector<int> dp_min(nums.size(), INT_MAX);

        dp_max[0] = nums[0];
        dp_min[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp_max[i] = max(max(nums[i], nums[i] * dp_max[i-1]), nums[i] * dp_min[i-1]);
            dp_min[i] = min(min(nums[i], nums[i] * dp_min[i-1]), nums[i] * dp_max[i-1]);

            cout << format("i = {}, max_i = {}, min_i = {}", i, dp_max[i], dp_min[i]);
        }
        return *max_element(dp_max.begin(), dp_max.end());
    }
};
