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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy;
        ListNode* node = &dummy;
        
        int carry = 0;
        while (l1 && l2) {
            int digit = l1->val + l2->val + carry;
            if (digit >= 10) {
                digit -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            node->next = new ListNode(digit);
            node = node->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
            node->next = l1;
        }
        else if (l2) {
            node->next = l2;
        }

        while (carry && node) {
            if (node->next == nullptr) {
                node->next = new ListNode{carry};
                break;
            }
            node = node->next;
            node->val += carry;
            if (node->val >= 10) {
                node->val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        
        return dummy.next;
    }
};
