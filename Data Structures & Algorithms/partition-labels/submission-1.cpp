class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> ch;

        for (int i = 0; i < s.size(); ++i) {
            auto it = ch.find(s[i]);
            if (it == ch.end()) {
                ch[s[i]] = {i, i};
            } else {
                it->second = {min(it->second.first, i), max(it->second.second, i)};
            }
        }

        vector<pair<int, int>> range;
        range.reserve(ch.size());

        for (auto [k, v] : ch) {
            range.push_back(v);
        }
        std::sort(range.begin(), range.end());

        for (int i = 0; i < range.size(); ++i) {
            cout << range[i].first << ", " << range[i].second << endl;
        }

        vector<pair<int, int>> res;
        res.push_back(range[0]);
    
        for (int i = 1; i < range.size(); ++i) {
            if (res.back().second > range[i].first) {
                res.back().second = max(res.back().second, range[i].second);
            } else {
                res.push_back(range[i]);
            }
        }
        vector<int> result;
        for (auto [s, e] : res) {
            result.push_back(e - s + 1);
        }
        return result;
    }
};
