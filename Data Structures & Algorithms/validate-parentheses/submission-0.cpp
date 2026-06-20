class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return false;
        }

        std::stack<char> st;
        auto valid_pair = [](char l, char r) {
            return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
        };

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else 
            {
                if (valid_pair(st.top(), s[i])) {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        return st.empty();
    }
};
