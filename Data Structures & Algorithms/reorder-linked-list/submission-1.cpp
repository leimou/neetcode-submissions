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

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;            
            slow = slow->next;
        }
        if (prev) {
            prev->next = nullptr;
        }
        else {
            return;
        }

        ListNode* tail = reverse(slow);        
        ListNode dummy;
        ListNode* iter = &dummy;

        while (head && tail) {
            iter->next = head;
            head = head->next;
            iter = iter->next;

            iter->next = tail;
            tail = tail->next;
            iter = iter->next;
        }
        if (head) {
            iter->next = head;
        }
        if (tail) {
            iter->next = tail;
        }
    }
};
