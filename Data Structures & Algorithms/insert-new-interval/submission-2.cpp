class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
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
    }
};
