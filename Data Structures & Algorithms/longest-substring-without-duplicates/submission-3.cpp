class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // (char -> index)
        std::unordered_map<char, int> m;

        if (s.empty()) {
            return 0;
        }

        int result = 0;
        size_t l = 0, r = 0;
        while (r < s.size())
        {
            auto [it, inserted] = m.try_emplace(s[r], r);
            if (!inserted) {
                int index = it->second;
                if (index >= l) {
                    l = it->second + 1;
                }
                it->second = r;
            }
            cout << "l = " << l << " r = " << r << endl;
            result = std::max(result, static_cast<int>(r - l + 1));
            ++r;
        }
        return result;
    }
};
