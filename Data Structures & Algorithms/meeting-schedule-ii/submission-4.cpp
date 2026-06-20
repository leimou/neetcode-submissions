/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
        [](auto& a, auto& b) {
            return a.start < b.start;
        });

        priority_queue<int, std::vector<int>, std::greater<int>> hp;

        for (const auto& interval : intervals) {
            if (!hp.empty() && hp.top() <= interval.start)
            {
                hp.pop();
            }
            hp.push(interval.end);
        }
        return hp.size();
    }
};
