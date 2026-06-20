class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[l] < nums[mid]) {
                if (nums[mid] > nums[r]) {
                    // Right half
                    l = mid;
                } else {
                    r = mid;
                }
            }
            else if (nums[l] == nums[mid]) { 
                return std::min(nums[l], nums[r]);
            }
            else {  // nums[l] > nums[mid]
                r = mid;                
            }
        }
        return nums[l];
    }
};
