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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0, head};
        ListNode* prev = &dummy;

        ListNode* iter = head;
        ListNode* prevHead = head;
        ListNode* prevTail = nullptr;

        while (iter)
        {
            int i = 0;
            while (iter && i < k)
            {
                prev = iter;
                iter = iter->next;
                ++i;
            }
            if (i < k) {
                break;
            }
            prev->next = nullptr;

            ListNode* reversed = reverse(prevHead);
            if (prevHead == head)
            {
                dummy.next = reversed;
            }
            prevHead->next = iter;
            if (prevTail) {
                prevTail->next = reversed;
            }
            prevTail = prevHead;
            prevHead = iter;
        }
        return dummy.next;
    }
};
