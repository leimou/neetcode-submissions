class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& nums, int start, int end)
    {
        if (start == end)
        {
            result.push_back(current);
        }
        else {
            current.push_back(nums[start]);
            backtrack(result, current, nums, start + 1, end);

            current.pop_back();
            backtrack(result, current, nums, start + 1, end);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(result, current, nums, 0, nums.size());
        return result;
    }
};
