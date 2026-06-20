class Solution {
public:
    int count(int i)
    {
        int ret = 0;
        while (i) {
            ret += (i & 1);
            i >>= 1;
        }
        return ret;
    }

    vector<int> countBits(int n) {
        vector<int> ret;
        for (int i = 0; i <= n; ++i) {
            ret.push_back(count(i));
        }
        return ret;
    }
};
