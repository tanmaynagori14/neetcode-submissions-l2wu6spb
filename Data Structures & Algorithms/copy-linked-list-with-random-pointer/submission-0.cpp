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
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        // Step 1: Create copy nodes and store mapping
        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Assign next and random pointers
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];     // copy next
            mp[curr]->random = mp[curr->random]; // copy random
            curr = curr->next;
        }

        // Step 3: Return new head
        return mp[head];
    }
};
