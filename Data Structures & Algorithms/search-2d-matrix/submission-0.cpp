class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        size_t n = matrix.size();
        size_t m = matrix[0].size();

        size_t l = 0, r = m * n;
        while (l < r)
        {
            auto mid = (l + r) / 2;
            auto i = mid / m;
            auto j = mid % m;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return false;
    }
};
