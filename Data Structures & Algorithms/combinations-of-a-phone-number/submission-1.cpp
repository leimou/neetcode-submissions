class Solution {
public:
    vector<string> result;
    vector<string> num{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return result;
        }
        std::string current(digits.size(), ' ');
        dfs(digits, current, 0);
        return result;
    }

    void dfs(const string& digits, string& current, int i)
    {
        if (i == digits.size()) {
            result.push_back(current);
            return;
        }

        int idx = digits[i] - '0';
        const string& strs = num[idx];
        for (char c : strs) {
            current[i] = c;
            dfs(digits, current, i + 1);
        }
    }
};
