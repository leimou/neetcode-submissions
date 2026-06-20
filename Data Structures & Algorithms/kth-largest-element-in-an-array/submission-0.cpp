class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> hp;

        for (auto n : nums)
        {
            hp.push(n);
            if (hp.size() > k)
            {
                hp.pop();
            }
        }
        return hp.top();
    }
};
