class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;

        auto dfs = [&](auto&& self, int i)
        {
            if (i == nums.size()) {
                res.push_back(ans);
                return;
            }

            ans.push_back(nums[i]);
            self(self, i + 1);
            ans.pop_back();

            while (i + 1 < nums.size() && nums[i+1] == nums[i]) {
                ++i;
            }
            self(self, i + 1);
        };
        dfs(dfs, 0);
    
        return res;
    }
};
