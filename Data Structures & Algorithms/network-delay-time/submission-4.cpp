class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); ++i)
        {
            auto [u, v, t] = tuple{times[i][0], times[i][1], times[i][2]};
            adj[u].emplace_back(v, t);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> hp;
        unordered_set<int> visited;
    
        hp.push({0, k});

        int t = 0;
        while (!hp.empty())
        {
            auto [cost, node] = hp.top();
            hp.pop();

            if (visited.count(node)) {
                continue;
            }
            visited.insert(node);
            t = cost;

            for (auto& [nextNode, edgeCost] : adj[node]) {
                if (!visited.count(nextNode)) {
                    hp.push({edgeCost + cost, nextNode});
                }
            }
        }
        return visited.size() == n ? t : -1;
    }
};
