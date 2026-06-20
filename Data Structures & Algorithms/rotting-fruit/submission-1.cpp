class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int time = 0;
        int fresh = 0;
        std::queue<std::pair<int, int>> q;

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }

        int dirs[] = {1, 0, -1, 0, 1};
        while (!q.empty() && fresh > 0)
        {
            size_t levelSize = q.size();
            for (size_t k = 0; k < levelSize; ++k)
            {
                auto [i, j] = q.front();
                q.pop();
    
                for (size_t d = 0; d < 4; ++d)
                {
                    int ni = i + dirs[d];
                    int nj = j + dirs[d + 1];

                    if (ni >= rows || ni < 0 || nj < 0 || nj >= cols)
                    {
                        continue;
                    }

                    if (grid[ni][nj] != 1)
                    {
                        continue;
                    }

                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                    --fresh;
                }
            }
            ++time;
        }
        return fresh == 0 ? time : -1;
    }
};
