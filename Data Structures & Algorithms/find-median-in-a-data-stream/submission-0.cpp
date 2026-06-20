class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (first_.empty()) {
            first_.push(num);
        }
        else {
            if (num > first_.top()) {
                second_.push(num);
            }
            else {
                first_.push(num);
            }
        }

        if (first_.size() > second_.size() + 1) {
            int top = first_.top();
            first_.pop();
            second_.push(top);
        }
        else if (second_.size() > first_.size()) {
            int top = second_.top();
            second_.pop();
            first_.push(top);
        }
    }
    
    double findMedian() {
        if (first_.empty()) {
            return 0;
        }
        else if (first_.size() == second_.size() + 1)
        {
            if (!second_.empty())
                std::cout << std::format("1 {}, {}\n", first_.top(), second_.top());
            else
                std::cout << std::format("1 {}\n", first_.top());
            return first_.top();
        }
        else 
        {
            std::cout << std::format("2 {}, {}\n", first_.top(), second_.top());
            return (first_.top() + second_.top()) / 2.0;
        }
    }

private:
    std::priority_queue<int, vector<int>, std::less<int>> first_;
    std::priority_queue<int, vector<int>, std::greater<int>> second_;
};
