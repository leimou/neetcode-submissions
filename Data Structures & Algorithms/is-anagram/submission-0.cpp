class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> m;
        for (auto c : s)
        {
            m[c] += 1;
        }
        for (auto c : t)
        {
            m[c] -= 1;
        }

        for (auto [k, v] : m)
        {
            if (v != 0)
            {
                return false;
            }
        }
        return true;
    }
};
