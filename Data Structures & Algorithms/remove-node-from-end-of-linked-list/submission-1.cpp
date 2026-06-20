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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0, head};
        ListNode* iter = &dummy;
        ListNode* curr = head;

        int i = 0;
        for (i = 0; i < n; ++i)
        {
            curr = curr->next;
        }

        while (curr) {
            iter = iter->next;
            curr = curr->next;
        }
        iter->next = iter->next->next;
        return dummy.next;
    }
};
