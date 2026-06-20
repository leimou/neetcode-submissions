/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        queue<pair<Node*, Node*>> q;
        std::unordered_map<Node*, Node*> clonedMap;

        auto cloned_node = new Node{node->val};
        q.push({node, cloned_node});
        clonedMap[node] = cloned_node;

        while (!q.empty())
        {
            auto [node, cloned] = q.front();
            q.pop();

            for (auto nb : node->neighbors)
            {
                Node* cloned_nb = nullptr;
                auto it = clonedMap.find(nb);
                if (it == clonedMap.end())
                {
                    cloned_nb = new Node(nb->val);
                    q.push({nb, cloned_nb});
                    clonedMap[nb] = cloned_nb;
                }
                else 
                {
                    cloned_nb = it->second;
                }
                cloned->neighbors.push_back(cloned_nb);
            }
        }
        return cloned_node;
    }
};
