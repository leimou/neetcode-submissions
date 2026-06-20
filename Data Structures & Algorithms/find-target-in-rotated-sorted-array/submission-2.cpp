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
            if (target < nums[m]) {
                if (nums[l] < nums[m]) {
                    // left sorted
                    if (target < nums[l]) {
                        // target less than left minimum, search right side
                        l = m + 1;
                    }
                    else {
                        // target in left range
                        r = m - 1;
                    }
                }
                else {
                    // right sorted
                    if (target < nums[r]) {
                        // target less than right maximum, in right range
                        r = m - 1;
                    }
                    else {
                        // target larger than right maximum, search left side.
                        l = m + 1;
                    }
                }
            }
            else {
                // target > nums[m]
                if (nums[m] < nums[r]) {
                    // right sorted
                    if (target > nums[r]) {
                        // target larger than right maximum, search left
                        r = m - 1;
                    }
                    else {
                        // target smaller than right maximum, search right
                        l = m + 1;
                    }
                }
                else {
                    // nums[m] > nums[r]
                    // left sorted
                    if (target < nums[l]) {
                        // target less than left minimum, search right
                        l = m + 1;
                    }
                    else {
                        // target larger than left maximum, search right
                        l = m + 1;
                    }
                }
            }
        }
        return -1;
    }
};
