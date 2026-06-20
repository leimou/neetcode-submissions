class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;

    explicit DisjointSet(int n)
        : parent(n, 1)
        , size(n, 1)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        while (node != parent[node])
        {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool unionSet(int i, int j)
    {
        int setA = find(i);
        int setB = find(j);
        if (setA == setB) {
            return false;
        }
        if (size[setA] > size[setB]) {
            swap(setA, setB);
        }
        parent[setA] = setB;
        size[setB] += size[setA];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size()+1);
        for (const auto& edge : edges) {
            if (!ds.unionSet(edge[0], edge[1])) {
                return edge;
            }
        }
        return vector<int>();
    }
};
