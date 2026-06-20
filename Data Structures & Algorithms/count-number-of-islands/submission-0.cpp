class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cout << std::format("visit [{}, {}]", i, j) << endl;
                    dfs(grid, visited, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }

    void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }

        if (!visited[i][j] && grid[i][j] == '1') {
            cout << std::format("[{}, {}] = true", i, j) << endl;
            visited[i][j] = true;

            dfs(grid, visited, i - 1, j);
            dfs(grid, visited, i + 1, j);
            dfs(grid, visited, i, j - 1);
            dfs(grid, visited, i, j + 1);
        }
    }
};
