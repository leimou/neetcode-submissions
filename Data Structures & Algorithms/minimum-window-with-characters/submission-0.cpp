class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return string{};

        std::unordered_map<char, int> exist;
        std::unordered_map<char, int> window;

        for (char c : t) {
            exist[c]++;
        }

        size_t l = 0, r = 0;
        size_t have = 0, need = exist.size();
        size_t min_length = std::numeric_limits<size_t>::max();
        std::pair<int, int> result{-1, -1};

        while (r < s.size())
        {
            char c = s[r];
            window[c]++;
            
            if (exist.count(c) && window[c] == exist[c]) {
                ++have;
            }

            while (have == need) {
                size_t len = r - l + 1;
                if (len < min_length) {
                    min_length = len;
                    result = {l, r};
                }

                window[s[l]]--;
                if (exist.count(s[l]) && window[s[l]] < exist[s[l]]) {
                    --have;
                }
                ++l;
            }
            ++r;
        }
        return min_length == std::numeric_limits<size_t>::max() ? string{} : s.substr(result.first, min_length);
    }
};
