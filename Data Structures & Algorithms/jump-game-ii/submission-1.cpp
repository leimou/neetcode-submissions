class Solution {
public:
    int jump(vector<int>& nums) {
        int last = nums.size() - 1;
        int i = last - 1;
        int fastest = 0;
        int res = 0;

        while (last > 0) 
        {
            for (int i = 0; i < last; ++i) {
                if (nums[i] + i >= last) {
                    last = i;
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};
