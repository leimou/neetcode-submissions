class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current(2 * n, ' ');

        auto dfs = [&](auto&& self, int i, int open) {
            if (i == 2 * n) {
                result.push_back(current);
                return;
            }

            if (open == 0) {
                current[i] = '(';
                self(self, i + 1, open + 1);
            }
            else {
                int remain = 2 * n - 1 - i;
                if (remain > open) {
                    current[i] = '(';
                    self(self, i + 1, open + 1);
                    current[i] = ')';
                    self(self, i + 1, open - 1);
                }
                else {
                    current[i] = ')';
                    self(self, i + 1, open - 1);
                }
            }
        };
        dfs(dfs, 0, 0);
        return result;
    }
};
