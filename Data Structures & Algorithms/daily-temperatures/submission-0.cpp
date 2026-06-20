class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> ret(t.size(), 0);

        int i = 0;
        while (i < t.size()) {
            if (!st.empty() && t[i] > t[st.top()]) {
                ret[st.top()] = i - st.top();
                st.pop();
            } else {
                st.push(i);
                ++i;
            }
        }
        return ret;
    }
};
