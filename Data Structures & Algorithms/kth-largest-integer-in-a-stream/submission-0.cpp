class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (auto v : nums)
        {
            heap_.push(v);
            if (heap_.size() > k) {
                heap_.pop();
            }
        }
    }
    
    int add(int val) {
        heap_.push(val);
        if (heap_.size() > k_)
        {
            heap_.pop();
        }
        return heap_.top();
    }

    int k_{0};
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap_;
};
