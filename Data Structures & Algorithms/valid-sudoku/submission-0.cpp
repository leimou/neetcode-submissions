#include <array>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return false;

        std::array<int, 10> exists;
        exists.fill(0);

        auto valid = [&exists]()
        {
            if (std::any_of(exists.begin(), exists.end(), [](int value){ return value > 1; }))
            {
                return false;
            }
            return true;
        };

        for (size_t i = 0; i < board.size(); ++i)
        {
            exists.fill(0);
            for (size_t j = 0; j < board[i].size(); ++j) 
            {
                if (board[i][j] == '.') 
                    continue;

                int digit = board[i][j] - '0';
                ++exists[digit];
            }
            if (!valid())
            {
                return false;
            }
        }

        for (size_t j = 0; j < board[0].size(); ++j)
        {
            exists.fill(0);
            for (size_t i = 0; i < board.size(); ++i) {
                if (board[i][j] == '.')
                    continue;
                
                int digit = board[i][j] - '0';
                ++exists[digit];
            }
            if (!valid())
            {
                return false;
            }
        }
        exists.fill(0);

        for (size_t i = 0; i < 3; ++i)
        {
            for (size_t j = 0; j < 3; ++j)
            {
                exists.fill(0);
                size_t x = (i + 1) * 3;
                size_t y = (j + 1) * 3;
                  
                for (size_t s = i * 3; s < x; ++s)
                {
                    for (size_t t = j * 3; t < y; ++t)
                    {
                        if (board[s][t] == '.')
                            continue;
                        
                        int digit = board[s][t] - '0';
                        ++exists[digit];
                    }
                    if (!valid())
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
