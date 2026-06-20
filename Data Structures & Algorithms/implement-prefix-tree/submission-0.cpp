class PrefixTree {
public:
    PrefixTree() {
    }
    
    void insert(string word) {
        
        Node* node = &root;
        for (auto c : word)
        {
            int idx = c - 'a';
            if (node->ch[idx] == nullptr)
            {
                node->ch[idx] = new Node;
            }
            node = node->ch[idx];
        }
        if (node->ch[26] == nullptr)
        {
            node->ch[26] = new Node;
        }
    }
    
    bool search(string word) 
    {
        Node* node = &root;
        for (auto c : word)
        {
            int idx = c - 'a';
            if (node->ch[idx])
            {
                node = node->ch[idx];
            }
            else {
                return false;
            }
        }
        return node->ch[26] != nullptr;
    }
    
    bool startsWith(string prefix) {
        Node* node = &root;
        for (auto c : prefix)
        {
            int idx = c - 'a';
            if (node->ch[idx])
            {
                node = node->ch[idx];
            }
            else {
                return false;
            }
        }
        return true;
    }

private:
    struct Node
    {
        Node() {
            ch.fill(nullptr);
        }
        std::array<Node*, 27> ch;
    };
    Node root;
};
