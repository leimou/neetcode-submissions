class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector f(n, vector<bool>(n, false));

        int idx = 0;
        int len = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || f[i+1][j-1])) {
                    f[i][j] = true;
                    if (j - i + 1 > len) {
                        idx = i;
                        len = j - i + 1;
                    }
                }
            }
        }
        return s.substr(idx, len);
    }
};
