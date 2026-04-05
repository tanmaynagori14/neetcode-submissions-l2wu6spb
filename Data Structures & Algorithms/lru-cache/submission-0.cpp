class List {
    public:
        int key, value;
        List *next, *prev;
        List(int key, int val) {
            this->key = key;
            this->value = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class LRUCache {
    private:
        int cap, currNoOfNodes;
        List *head, *tail;
        unordered_map<int, List*> mp;
    public:
        LRUCache(int capacity) {
            this->cap = capacity;
            this->currNoOfNodes = 0;
            head = new List(-1, -1);
            tail = new List(-1, -1);
            head->prev = tail;
            tail->next = head;
        }

        void insertAtHead(List* node) {
            List *headPrev = head->prev;
            node->next = head;
            head->prev = node;
            node->prev = headPrev;
            headPrev->next = node;
        }

        void removeFromTail() {
            List* nodeToRemove = tail->next;
            List* tailNextNext = tail->next->next;
            tail->next = tailNextNext;
            tailNextNext->prev = tail;
            delete(nodeToRemove);
        }

        void modifyNodeprevNext(List* node) {
            List* nodeNext = node->next;
            List* nodePrev = node->prev;
            nodePrev->next = nodeNext;
            nodeNext->prev = nodePrev;
        }
        
        int get(int key) {
            if(mp.find(key) == mp.end()) return -1;
            List* node = mp[key];
            modifyNodeprevNext(node);
            insertAtHead(node);
            return node->value;
        }
        
        void put(int key, int value) {
            if(mp.find(key) == mp.end()) {
                List* node = new List(key, value);
                mp[key] = node;
                insertAtHead(node);
                currNoOfNodes++;
                if (currNoOfNodes > cap) {
                    List *node = tail->next;
                    int keyOfNode = node->key;
                    mp.erase(keyOfNode);
                    removeFromTail();
                    currNoOfNodes--;
                } 
            } else {
                List* node = mp[key];
                node->value = value;
                modifyNodeprevNext(node);
                insertAtHead(node);
            }
        }
};
