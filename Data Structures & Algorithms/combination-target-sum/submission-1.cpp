class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        std::sort(nums.begin(), nums.end());
        backtrack(result, nums, current, 0, target);
        return result;
    }

    void backtrack(vector<vector<int>>& result, const vector<int>& nums, vector<int>& current, int i, int remaining) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        if (i >= nums.size()) {
            return;
        }
        if (remaining - nums[i] < 0) {
            return;
        }

        current.push_back(nums[i]);
        backtrack(result, nums, current, i, remaining - nums[i]);
        current.pop_back();
        backtrack(result, nums, current, i+1, remaining);
    }
};
