class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        priority_queue<pair<int, int>> hp;

        for (int r = 0; r < k; ++r) {
            hp.push({nums[r], r});
        }

        vector<int> res;
        res.reserve(nums.size() - k);
        for (int r = 0; r < nums.size(); ++r) {
            hp.push({nums[r], r});
            if (r >= k - 1) {
                while (hp.top().second <= r - k) {
                    hp.pop();
                }
                res.push_back(hp.top().first);
            }
        }
        */
        vector<int> res;
        deque<int> q;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (!q.empty() && nums[q.back()] <= nums[r]) {
                q.pop_back();
            }
            q.push_back(r);

            if (r - l + 1 > k) {
                ++l;
                if (q.front() < l) {
                    q.pop_front();
                }
            }
            if (r - l + 1 == k) {
                res.push_back(nums[q.front()]);
            }
        }

        return res;
    }
};
