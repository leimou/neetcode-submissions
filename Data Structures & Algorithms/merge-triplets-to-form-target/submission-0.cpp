class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = -1, b = -1, c = -1;
        for (int i = 0; const auto& trip : triplets) {
            if (trip[0] == target[0] && trip[1] <= target[1] && trip[2] <= target[2]) {
                a = i;
            }
            if (trip[0] <= target[0] && trip[1] == target[1] && trip[2] <= target[2]) {
                b = i;
            }
            if (trip[0] <= target[0] && trip[1] <= target[1] && trip[2] == target[2]) {
                c = i;
            }
            ++i;
        }
        return a >= 0 && b >= 0 && c >= 0;
    }
};
