class Solution {
public:
    struct PointLess
    {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs)
        {
            return distance(lhs) < distance(rhs);
        }

        double distance(const vector<int>& p)
        {
            return sqrt(p[0] * p[0] + p[1] * p[1]);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<vector<int>, vector<vector<int>>, PointLess> hp;

        for (auto& p : points)
        {
            hp.push(p);
            if (hp.size() > k)
            {
                hp.pop();
            }
        }

        vector<vector<int>> result;
        while (!hp.empty())
        {
            result.push_back(hp.top());
            hp.pop();
        }
        return result;
    }
};
