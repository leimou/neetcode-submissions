class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i]] = i;
        }

        vector<int> res;
        int i = 0;
        int start = 0;
        int end = -1;

        while (i < s.size()) {
            end = max(end, lastIndex[s[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
                end = -1;
            }
            ++i;
        }
        return res;
    }
};
