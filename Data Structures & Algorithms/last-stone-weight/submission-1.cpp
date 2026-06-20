class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> hp;
        for (auto n : stones) {
            hp.push(n);
        }

        while (hp.size() > 1)
        {
            int x = hp.top(); hp.pop();
            int y = hp.top(); hp.pop();

            int z = x - y;

            cout << x << " " << y << " " << z << endl;

            if (z > 0) {
                hp.push(z);
            }
        }
        return hp.empty() ? 0 : hp.top();
    }
};
