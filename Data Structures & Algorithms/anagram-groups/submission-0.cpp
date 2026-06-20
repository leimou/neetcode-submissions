class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> m;
        for (const auto& s : strs)
        {
            string sorted = s;
            std::sort(sorted.begin(), sorted.end());
            auto ret = m.emplace(sorted, std::vector<string>{s});
            if (!ret.second)
            {
                ret.first->second.emplace_back(s);
            }
        }

        vector<vector<string>> ret;
        for (const auto& [k, v] : m)
        {
            ret.emplace_back(v);
        }
        return ret;
    }
};
