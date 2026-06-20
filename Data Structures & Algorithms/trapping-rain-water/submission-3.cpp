class Solution {
public:
    int trap(vector<int>& height) {
        size_t l = 0, r = height.size() - 1;
        int lmax = height[l], rmax = height[r];

        int result = 0;
        while (l < r) {
            if (lmax < rmax) {
                ++l;
                lmax = std::max(lmax, height[l]);
                result += lmax - height[l];
            }
            else {
                --r;
                rmax = std::max(rmax, height[r]);
                result += rmax - height[r];
            }
        }
        return result;
    }
};
