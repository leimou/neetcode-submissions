class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result;
        if (strs.empty())
        {
            return result;
        }

        for (const auto& s : strs)
        {
            result.append(std::to_string(s.size()));
            result.push_back('#');
            result.append(s);
        }
        return result;
    }

    vector<string> decode(string s) 
    {
        std::vector<std::string> result;

        size_t i = 0;
        while (i < s.size())
        {
            size_t j = s.find('#', i);
            size_t l = std::stoi(s.substr(i, j - i));
            result.push_back(s.substr(j+1, l));
            i = j + 1 + l;
        }
        return result;
    }
};
