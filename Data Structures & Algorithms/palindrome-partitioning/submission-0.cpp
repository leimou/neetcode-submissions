class Solution {
public:
    vector<vector<string>> res;
    vector<string> ans;

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            }
            else {
                return false;
            }
        }
        return true;
    }

    void dfs(const string& s, int i) {
        if (i == s.size()) {
            res.push_back(ans);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s, i, j)) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }
};
