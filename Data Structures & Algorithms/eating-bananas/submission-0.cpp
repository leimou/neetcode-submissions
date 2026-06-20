class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());

        int res = 0;
        while (l <= r)
        {
            int k = (l + r) / 2;
            uint64_t totalTime = 0;

            for (size_t i = 0; i < piles.size(); ++i) {
                totalTime += ceil(static_cast<double>(piles[i]) / k);
            }

            if (totalTime <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
