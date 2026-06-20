class Solution {
public:
    static constexpr int32_t INF = std::numeric_limits<int32_t>::max();

    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return;
        }

        int rows = grid.size();
        int cols = grid[0].size();

        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        constexpr int dir[] = {1, 0, -1, 0, 1};
        while (!q.empty())
        {
            int level_size = q.size();
            for (int k = 0; k < level_size; ++k)
            {
                auto [i, j] = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d)
                {
                    int ni = i + dir[d];
                    int nj = j + dir[d+1];

                    if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size())
                    {
                        continue;
                    }

                    if (grid[ni][nj] == -1) {
                        continue;
                    }
                    else if (grid[ni][nj] == INF)
                    {
                        grid[ni][nj] = grid[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }
};
