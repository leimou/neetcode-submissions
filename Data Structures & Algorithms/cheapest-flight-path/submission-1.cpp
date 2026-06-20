class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (auto& f : flights) {
            // u -> (v, w)
            adj[f[0]].emplace_back(f[1], f[2]);
        }

        for (int i = 0; i < k + 1; ++i)
        {
            vector<int> prev = dist;

            for (auto& f : flights) {
                auto u = f[0];
                auto v = f[1];
                auto w = f[2];

                if (prev[u] == INT_MAX) {
                    continue;
                }

                if (prev[u] + w < dist[v]) {
                    dist[v] = prev[u] + w;
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
