class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> s;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            auto it = s.find(target - nums[i]);
            if (it == s.end())
            {
                s.emplace(nums[i], i);
            }
            else {
                return vector<int>{it->second, i};
            }
        }
        return vector<int>();
    }
};
