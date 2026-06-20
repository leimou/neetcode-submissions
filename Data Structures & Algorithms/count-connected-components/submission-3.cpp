class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    explicit DisjointSet(size_t n)
        : parent(n, 0)
        , size(n, 1)
    {
        for (size_t i = 0; i < n; ++i)
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
        if (size[setA] > size[setB])
        {
            swap(setA, setB);
        }
        parent[setA] = setB;
        size[setB] += size[setA];
        return true;
    }
};

class Solution {
public:  
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int res = n;
        for (auto& edge : edges) {
            if (ds.unionSet(edge[0], edge[1])) {
                --res;
            }
        }
        return res;
    }
};
