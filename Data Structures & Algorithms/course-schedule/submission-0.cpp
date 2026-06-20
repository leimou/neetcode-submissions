class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty())
        {
            return true;
        }

        unordered_map<int, int> indegree; // node -> number of edges from node
        unordered_multimap<int, int> edges; // from -> to
        for (const auto& pre : prerequisites) {
            int from = pre[0];
            int to = pre[1];

            indegree[to]++;
            edges.emplace(from, to);
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree.count(i) == 0 || indegree[i] == 0)
            {
                q.push(i);
                if (indegree[i] == 0)
                {
                    indegree.erase(i);
                }
            }
        }

        while (!q.empty())
        {
            auto c = q.front();
            q.pop();

            auto [begin, end] = edges.equal_range(c);
            if (begin == edges.end()) {
                continue;
            }
            for (auto i = begin; i != end; ++i)
            {
                int target = i->second;
                auto j = indegree.find(target);
                if (j != indegree.end())
                {
                    j->second--;
                    if (j->second == 0)
                    {
                        q.push(target);
                        indegree.erase(j);
                    }
                }
            }
        }
        return indegree.empty();
    }
};
