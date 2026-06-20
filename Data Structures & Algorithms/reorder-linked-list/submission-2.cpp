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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;            
            slow = slow->next;
        }
        return slow;
    }

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
        ListNode* middle = middleNode(head);
        ListNode* tail = reverse(middle);        

        while (tail->next) {
            auto next = head->next;
            auto next2 = tail->next;
            head->next = tail;
            tail->next = next;
            head = next;
            tail = next2;
        }
    }
};
