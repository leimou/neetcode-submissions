class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }

        int i = nums.size() - 2;
        int last = nums.size() - 1;

        while (i >= 0) {
            int dist = last - i;
            if (nums[i] >= dist) {
                last = i;
            }
            --i;
        }
        return last == 0;
    }
};
