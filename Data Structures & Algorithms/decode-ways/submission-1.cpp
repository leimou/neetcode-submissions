class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);

        // 1 <= s[i] <= 9
        // s[i] == "1", s[2] any
        // s[2] == "2", s[2] <= 6 >=0
        if (s[0] == '0') {
            return 0;
        }
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] >= '1' && s[i] <= '9')
            {
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                    dp[i+1] = dp[i-1] + dp[i];
                }
                else {
                    dp[i+1] = dp[i];
                }
            }
            else {
                if (s[i-1] == '1' || s[i-1] == '2')
                {
                    dp[i+1] = dp[i-1];
                }
                else {
                    return 0;
                }
            }

        }
        return dp[s.size()];
    }
};
