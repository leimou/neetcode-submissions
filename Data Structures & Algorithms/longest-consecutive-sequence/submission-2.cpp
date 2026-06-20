class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());

        int ret = 0;
        for (int n : nums)
        {
            int streak = 0, curr = n;
            while (s.count(curr) > 0)
            {
                ++streak;
                ++curr;
            }
            ret = std::max(ret, streak);
        }
        return ret;
    }
};
