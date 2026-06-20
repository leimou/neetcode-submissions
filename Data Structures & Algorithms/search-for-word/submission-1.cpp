class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if (m == 1 && n == 1) {
            return word.size() == 1 && word[0] == board[0][0];
        }

        vector<vector<uint8_t>> visited(m, vector<uint8_t>(n, 0));

        array dir = {-1, 0, 1, 0, -1};
        auto dfs = [&](this auto&& dfs, int idx, int i, int j) {
            if (idx == word.size()) {
                return true;
            }

            if (!visited[i][j] && board[i][j] == word[idx]) {
                visited[i][j] = true;

                for (int d = 0; d < 4; ++d)
                {
                    int di = i + dir[d];
                    int dj = j + dir[d + 1];

                    if (di < 0 || di >= m || dj < 0 || dj >= n) {
                        continue;
                    }

                    bool found = dfs(idx + 1, di, dj);
                    if (found) {
                        return true;
                    }
                }
                visited[i][j] = false;
            }
            return false;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    auto found = dfs(0, i, j);
                    if (found) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
