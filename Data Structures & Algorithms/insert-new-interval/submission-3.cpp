class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
        vector<vector<int>> ret;
        size_t i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ret.push_back(intervals[i]);
            ++i;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            ++i;
        }
        ret.push_back(newInterval);

        while (i < intervals.size())
        {
            ret.push_back(intervals[i]);
            i++;
        }

        return ret;
        */

        int l = 0, r = intervals.size();
        int start = 0, end = 0;
    
        while (l < r) {
            int m = (l + r) / 2;
            if (intervals[m][0] < newInterval[0]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        intervals.insert(intervals.begin() + l, newInterval);

        vector<vector<int>> ret;
        for (const auto& interval : intervals) {
            if (ret.empty() || ret.back()[1] < interval[0]) {
                ret.push_back(interval);
            } else {
                ret.back()[1] = max(ret.back()[1], interval[1]);
            }
        }

        return ret;
    }
};
