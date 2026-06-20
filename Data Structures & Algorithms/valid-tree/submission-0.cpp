class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        if (!dfs(adj, visited, 0, -1))
        {
            return false;
        }

        return visited.size() == n;
    }

    bool dfs(const vector<vector<int>>& adj, unordered_set<int>& visited, int child, int parent)
    {
        if (visited.count(child)) {
            return false;
        }
        visited.insert(child);
        for (int nei : adj[child]) {
            if (nei == parent) {
                continue;
            }
            if (!dfs(adj, visited, nei, child)) {
                return false;
            }
        }
        return true;
    }
};
