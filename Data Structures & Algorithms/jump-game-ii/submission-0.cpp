class Solution {
public:
    int jump(vector<int>& nums) {
        int last = nums.size() - 1;
        int i = last - 1;
        int fastest = 0;
        int res = 0;

        while (last > 0) 
        {
            i = last - 1;
            while (i >= 0)
            {
                if (nums[i] >= last - i)
                {
                    fastest = i;
                }
                --i;
            }
            last = fastest;
            ++res;
        }
        return res;
    }
};
