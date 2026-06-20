class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int area = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1) {
                    auto island = dfs(grid, visited, i, j);
                    area = max(area, island);
                }
            }
        }
        return area;
    }

    int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }
        if (!visited[i][j] && grid[i][j] == 1) {
            visited[i][j] = true;

            int area = 0;
            area += dfs(grid, visited, i - 1, j);
            area += dfs(grid, visited, i + 1, j);
            area += dfs(grid, visited, i, j - 1);
            area += dfs(grid, visited, i, j + 1);

            return area + 1;
        }
        return 0;
    }
};
