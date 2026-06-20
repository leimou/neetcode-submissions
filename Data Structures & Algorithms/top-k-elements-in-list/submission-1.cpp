class Solution {
public:
    using ElementType = std::pair<int, int>;
    struct LessThan
    {
        bool operator()(const ElementType& lhs, const ElementType& rhs)
        {
            return lhs.first < rhs.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        for (int n : nums)
        {
            m[n]++;
        }


        std::priority_queue<ElementType, std::vector<ElementType>, LessThan> hp;
        for (auto [k, freq] : m)
        {
            hp.push(std::make_pair(freq, k));
        }

        vector<int> result(k);
        for (int i = 0; i < k; ++i)
        {
            result[i] = hp.top().second;
            hp.pop();
        }
        return result;
    }
};
