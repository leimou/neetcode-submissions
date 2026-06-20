/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> copy;
        copy[nullptr] = nullptr;

        Node* iter = head;
        while (iter) {
            Node* newNode = new Node{iter->val};
            copy[iter] = newNode;
            iter = iter->next;
        }

        iter = head;
        while (iter) {
            copy[iter]->next = copy.at(iter->next);
            copy[iter]->random = copy.at(iter->random);
            iter = iter->next;
        }
        return copy[head];
    }
};
