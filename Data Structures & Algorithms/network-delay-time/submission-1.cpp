class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const auto& time : times) {
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> hp;
        hp.push({0, k});

        unordered_set<int> visited;
        int t = 0;

        while (!hp.empty())
        {
            auto current = hp.top();
            hp.pop();

            int node = current.second;
            int cost = current.first;
            if (visited.count(node)) {
                continue;
            }
            visited.insert(node);
            t = cost;

            auto it = edges.find(node);
            if (it != edges.end())
            {
                for (const auto& next : it->second)
                {
                    int n = next.first;
                    int c = next.second;
                    if (!visited.count(n)) {
                        hp.push({c + cost, n});
                    }
                }
            }
        }
        return visited.size() == n ? t : -1;
    }
};
