class Solution {
public:
    enum class Op {
        Add,
        Sub,
        Mul,
        Div
    };

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        auto compute = [&](Op op)
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            switch (op) {
                case Op::Add: return a + b;
                case Op::Sub: return a - b;
                case Op::Mul: return a * b;
                default: return a / b;
            }
        };

        for (const auto& tok : tokens) {
            if (tok == "+") {
                st.push(compute(Op::Add));
            }
            else if (tok == "-") {
                st.push(compute(Op::Sub));
            }
            else if (tok == "*") {
                st.push(compute(Op::Mul));
            }
            else if (tok == "/") {
                st.push(compute(Op::Div));
            }
            else {
                st.push(stoi(tok));
            }
        }
        return st.top();
    }
};
