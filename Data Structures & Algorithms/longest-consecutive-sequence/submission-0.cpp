class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s;

        for (auto n : nums)
        {
            s.insert(n);
        }

        std::vector<int> seq_start;
        for (auto n : nums)
        {
            if (s.count(n - 1) == 0)
            {
                seq_start.push_back(n);
            }
        }

        int ret = 0;
        for (int n : seq_start)
        {
            int m = n, count = 0;
            while (s.count(m) > 0)
            {
                ++count;
                ret = std::max(ret, count);
                ++m;
            }
        }
        return ret;
    }
};
