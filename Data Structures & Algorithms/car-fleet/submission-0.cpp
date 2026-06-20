class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); ++i) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());

        stack<double> st;
        for (size_t i = 0; i < cars.size(); ++i) {
            double t = (double)(target - cars[i].first) / cars[i].second;
            while (!st.empty() && st.top() <= t) {
                st.pop();
            }
            st.push(t);
        }
        return st.size();
    }
};
