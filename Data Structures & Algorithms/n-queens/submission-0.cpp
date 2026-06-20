class Solution {
public:
    string result(int i, int n)
    {
        string res(n, '.');
        res[i] = 'Q';
        return res;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;        
        vector<int> queens(n);
        vector<int> cols(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        auto dfs = [&](auto&& self, int r)
        {
            if (r == n)
            {
                ret.emplace_back();
                for (int i = 0; i < n; ++i)
                {
                    ret.back().emplace_back(result(queens[i], n));
                }
                return;
            }

            for (int c = 0; c < n; ++c)
            {
                int rc = r - c + n - 1;
                if (!cols[c] && !diag1[r + c] && !diag2[rc])
                {
                    queens[r] = c;
                    cols[c] = diag1[r + c] = diag2[rc] = 1;
                    self(self, r + 1);
                    cols[c] = diag1[r + c] = diag2[rc] = 0;
                }
            }
        };
        dfs(dfs, 0);
        return ret;
    }
};
