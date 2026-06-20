class Solution {
public:
    using MinHeap = std::priority_queue<int, vector<int>, std::greater<int>>;
    using MaxHeap = std::priority_queue<int, vector<int>, std::less<int>>;

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        MaxHeap small;
        MinHeap large;

        size_t i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                addValue(nums1[i++], small, large);
            } else {
                addValue(nums2[j++], small, large);
            }
        }

        while (i < nums1.size()) {
            addValue(nums1[i++], small, large);
        }

        while (j < nums2.size()) {
            addValue(nums2[j++], small, large);
        }

        if (small.size() == large.size()) {
            return small.empty() ? 0.0 : (small.top() + large.top()) / 2.0;
        }
        else {
            return small.top();
        }
    }

    void addValue(int value, MaxHeap& small, MinHeap& large)
    {
        if (small.size() < large.size() + 1) {
            if (small.empty() || value < large.top()) {
                cerr << format("Push {} to small", value) << endl;
                small.push(value);
            }
            else {
                cerr << format("Move {} to small, push {} to large", large.top(), value) << endl;
                small.push(large.top());
                large.pop();
                large.push(value);
            }
        }
        else 
        {
            if (large.empty() || value > large.top()) {
                cerr << format("Push {} to large", value) << endl;
                large.push(value);
            }
            else {
                cerr << format("Move {} to large, push {} to small", small.top(), value) << endl;
                large.push(small.top());
                small.pop();
                small.push(value);
            }
        }
    }
};
