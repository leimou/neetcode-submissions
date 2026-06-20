class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> selected(nums.size(), false);
        vector<int> current(nums.size());

        dfs(nums, current, selected, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& current, vector<bool>& selected, int i)
    {
        if (i == nums.size()) {
            res.push_back(current);
            return;
        }
        
        for (int j = 0; j < nums.size(); ++j)
        {
            if (!selected[j])
            {
                current[i] = nums[j];
                selected[j] = true;
                dfs(nums, current, selected, i + 1);
                selected[j] = false;
            }
        }
    }
    
};
