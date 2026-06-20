class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dist = [](const vector<int>& a, const vector<int>& b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };

        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto d = dist(points[i], points[j]);
                adj[i].emplace_back(j, d);
                adj[j].emplace_back(i, d);
            }
        }

        vector<int> visited(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> hp;

        hp.push({0, 0});  // start from point 0
        int total = 0;
        int count = 0;

        while (!hp.empty())
        {
            auto [cost, u] = hp.top();
            hp.pop();

            if (visited[u]) 
                continue;

            visited[u] = 1;
            total += cost;
            count += 1;

            for (auto [v, w] : adj[u])
            {
                if (!visited[v]) {
                    hp.push({w, v});
                }
            }
        }
        if (count == n) {
            return total;
        }
        return -1;
    }
};
