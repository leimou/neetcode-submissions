class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t l = 0, r = nums.size();
        while (l < r)
        {
            auto m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return -1;
    }
};
