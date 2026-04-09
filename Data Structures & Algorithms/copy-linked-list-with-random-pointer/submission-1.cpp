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

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         // there is one solution using the hash map. 
//         // basically create one hashmap <Node*, Node*> old->new and traverse whole list and store the old->new 
//         // Now againtraverse the whole list and do next and random connections and finally we can return mp[headofOldList]
//         if (!head) return NULL;

//         unordered_map<Node*, Node*> mp;

//         // Step 1: Create copy nodes and store mapping
//         Node* curr = head;
//         while (curr) {
//             mp[curr] = new Node(curr->val);
//             curr = curr->next;
//         }

//         // Step 2: Assign next and random pointers
//         curr = head;
//         while (curr) {
//             mp[curr]->next = mp[curr->next];     // copy next
//             mp[curr]->random = mp[curr->random]; // copy random
//             curr = curr->next;
//         }

//         // Step 3: Return new head
//         return mp[head];
//     }
// };


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Insert copied nodes
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;

            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = nextNode;

            temp = nextNode;
        }

        // Step 2: Assign random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;

            temp = temp->next->next;
        }

        // Step 3: Separate lists
        temp = head;
        Node* dummy = new Node(-1);
        Node* copy = dummy;

        while (temp) {
            Node* nextNode = temp->next->next;

            Node* copyNode = temp->next;
            copy->next = copyNode;

            temp->next = nextNode;

            copy = copyNode;
            temp = nextNode;
        }

        return dummy->next;
    }
};