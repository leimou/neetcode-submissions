class Solution {
public:
    bool checkValidString(string s) {
        stack<char> left, star;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*') {
                star.push(i);
            }
            else if (s[i] == '(') {
                left.push(i);
            }
            else {
                if (left.empty() && star.empty()) {
                    return false;
                }
                else if (left.empty()) {
                    star.pop();
                }
                else {
                    left.pop();
                }
            }
        }

        while (!left.empty() && !star.empty())
        {
            if (left.top() > star.top())
            {
                return false;
            }
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};
