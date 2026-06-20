class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        auto squareSum = [](int m) {
            int sum = 0;
            while (m > 0) {
                int digit = m % 10;
                sum += digit * digit;
                m /= 10;
            }
            return sum;
        };

        cout << squareSum(100) << endl;
        cout << squareSum(101) << endl;

        while (n != 1) 
        {
            n = squareSum(n);
            cout << n << endl;
            if (seen.count(n)) {
                return false;
            }
            seen.insert(n);
        }
        return true;
    }
};
