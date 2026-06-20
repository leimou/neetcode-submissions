class Solution {
public:
    struct IntervalGreater
    {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[0] > b[0]) {
                return true;
            }
            else if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            else {
                return false;
            }
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::priority_queue<vector<int>, vector<vector<int>>, IntervalGreater> hp;
        
        for (const auto& interval : intervals) {
            hp.push(interval);
        }

        vector<vector<int>> ret;
        while (!hp.empty()) {
            if (ret.empty() || hp.top()[0] > ret.back()[1]) {
                ret.push_back(hp.top());
            }
            else {
                ret.back()[1] = max(ret.back()[1], hp.top()[1]);
            }
            hp.pop();
        }
        return ret;
    }
};
