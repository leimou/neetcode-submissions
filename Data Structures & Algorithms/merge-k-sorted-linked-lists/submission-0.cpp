/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct NodeGreater
    {
        bool operator()(ListNode* lhs, ListNode* rhs)
        {
            return lhs->val > rhs->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {    
        if (lists.empty()) {
            return nullptr;
        }

        using ListNodePair = std::pair<ListNode*, size_t>;
        std::priority_queue<ListNode*, vector<ListNode*>, NodeGreater> hp;
        for (size_t i = 0; i < lists.size(); ++i)
        {
            hp.push(lists[i]);
        }

        ListNode dummy;
        ListNode* tail = &dummy;
        
        while (!hp.empty())
        {
            auto leastNode = hp.top();
            tail->next = leastNode;

            if (leastNode && leastNode->next) {
                hp.push(leastNode->next);
            }
            tail = leastNode;
            hp.pop();
        }
        return dummy.next;
    }
};
