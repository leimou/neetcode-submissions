class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        unordered_map<int, int> count;
        for (int n : hand) {
            count[n]++;
        }

        priority_queue<int, vector<int>, greater<int>> hp;
        for (auto [k, v] : count) {
            hp.push(k);
        }

        while (!hp.empty()) {
            int min = hp.top();
            for (int i = min; i < min + groupSize; ++i) {
                if (count.count(i) == 0) {
                    return false;
                }
                --count[i];
                if (count[i] == 0) {
                    if (i != hp.top()) {
                        return false;
                    }
                    hp.pop();
                }
            }
        }
        return true;
    }
};
