class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (auto i : nums)
        {
            if (s.contains(i))
            {
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};