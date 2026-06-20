class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (target == nums[m]) {
                return m;
            }

            if (nums[l] <= nums[m]) {
                if (target < nums[l] || target > nums[m]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else {
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
