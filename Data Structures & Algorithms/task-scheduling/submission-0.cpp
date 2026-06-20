class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        std::vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        std::priority_queue<int> hp;
        for (int cnt : freq)
        {
            if (cnt > 0) {
                hp.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!hp.empty() || !q.empty())
        {
            ++time;
            if (!hp.empty())
            {
                int freq = hp.top() - 1;
                hp.pop();

                if (freq > 0)
                {
                    q.push({freq, time + n});
                }
            }
            else {
                time = q.front().second;
            }

            if (!q.empty() && q.front().second == time) {
                hp.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
