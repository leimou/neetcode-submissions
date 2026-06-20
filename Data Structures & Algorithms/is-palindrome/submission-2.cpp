class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            char l = s[i];
            char r = s[j];

            if (!std::isalnum(l))
            {
                ++i;
                continue;
            }

            if (!std::isalnum(r))
            {
                --j;
                continue;
            }

            if (std::tolower(l) == std::tolower(r))
            {
                ++i;
                --j;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};
