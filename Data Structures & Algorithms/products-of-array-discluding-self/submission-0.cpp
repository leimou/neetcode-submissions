class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        vector<int> l_prefix(nums.size(), 0);
        vector<int> r_prefix(nums.size(), 0);

        l_prefix[0] = 1;
        r_prefix[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            l_prefix[i] = l_prefix[i - 1] * nums[i - 1];
            cout << l_prefix[i] << " ";
        }
        cout << endl;

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            r_prefix[i] = r_prefix[i + 1] * nums[i + 1];
            cout << r_prefix[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < nums.size(); ++i)
        {
            result[i] = l_prefix[i] * r_prefix[i];
        }
        return result;
    }
};
