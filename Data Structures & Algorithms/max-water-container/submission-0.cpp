class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = static_cast<int>(heights.size());
        
        int result = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = i + 1; j < r; ++j)
            {
                int area = std::min(heights[i], heights[j]) * (j - i);
                result = std::max(result, area);
            }
        }
        return result;
    }
};
