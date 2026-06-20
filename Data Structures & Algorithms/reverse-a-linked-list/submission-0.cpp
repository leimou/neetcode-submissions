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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* newHead = head;
        while (head->next)
        {
            auto nextNode = head->next;
            if (nextNode) {
                head->next = nextNode->next;
                nextNode->next = newHead;
            }
            newHead = nextNode;
        }
        return newHead;
    }
};
