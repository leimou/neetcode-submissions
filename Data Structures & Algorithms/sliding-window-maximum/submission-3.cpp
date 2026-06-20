class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> hp;

        for (int i = 0; i < k; ++i) {
            hp.push({nums[i], i});
        }

        vector<int> res;
        res.reserve(nums.size());
        res.push_back(hp.top().first);

        for (int i = k; i < nums.size(); ++i) {
            hp.push({nums[i], i});
            while (hp.top().second <= i - k) {
                hp.pop();
            }
            res.push_back(hp.top().first);
        }

        return res;
    }
};
