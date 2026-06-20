class LRUCache {
public:
    LRUCache(int capacity) {
        dummy.next = &dummy;
        dummy.prev = &dummy;
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = kvMap_.find(key);
        if (it == kvMap_.end())
        {
            return -1;
        }

        auto node = it->second;
        removeNode(*node);
        addNode(*node);

        return node->value;
    }
    
    void put(int key, int value) {
        auto it = kvMap_.find(key);
        if (it == kvMap_.end())
        {
            Node* node = nullptr;
            if (kvMap_.size() == capacity_)
            {
                node = dummy.prev;
                removeNode(*node);
                kvMap_.erase(node->key);
            }
            else {
                node = new Node{};
            }
            node->key = key;
            node->value = value;
            kvMap_[key] = node;            
            addNode(*node);
        }
        else {
            auto node = it->second;
            node->value = value;

            removeNode(*node);
            addNode(*node);
        }
    }

private:
    struct Node {
        int key{-1};
        int value{-1};
        Node* next{nullptr};
        Node* prev{nullptr};
    };

    void addNode(Node& node)
    {
        node.next = dummy.next;
        node.prev = &dummy;
        dummy.next->prev = &node;
        dummy.next = &node;
    }

    void removeNode(Node& node)
    {
        node.prev->next = node.next;
        node.next->prev = node.prev;
        node.prev = nullptr;
        node.next = nullptr;
    }

    Node dummy;
    unordered_map<int, Node*> kvMap_;
    int capacity_{0};
};
