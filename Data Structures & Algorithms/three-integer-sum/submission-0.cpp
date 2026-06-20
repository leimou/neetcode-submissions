class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;
        
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    --k;
                }
                else if (sum < 0) {
                    ++j;
                }
                else {
                    res.push_back({nums[i], nums[j], nums[k]});

                    ++j;
                    while (j < k && nums[j] == nums[j-1]) 
                        ++j;

                    --k;
                    while (k > j && nums[k] == nums[k+1])
                        ++k;
                }
            }
        }
        return res;
    }
};
