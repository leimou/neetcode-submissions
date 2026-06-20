class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> cur;
        std::sort(nums.begin(), nums.end());
        
        dfs(nums, cur, 0, 0, target);
        return res;
    }

    void dfs(const vector<int>& nums, vector<int>& cur, int i, int total, int target)
    {
        if (total == target) {
            res.push_back(cur);
            return;
        }

        int j = i;
        while (j < nums.size())
        {
            if (total + nums[j] > target) {
                return;
            }
            cur.push_back(nums[j]);
        
            dfs(nums, cur, j + 1, total + nums[j], target);
            cur.pop_back();

            int k = j;
            while (k < nums.size() && nums[k] == nums[j]) 
                ++k;
            j = k;
        }
    }
};
