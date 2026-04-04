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
    unordered_map<Node*, Node*> m;
    Node* dfs(Node *node) {
        int val = node->val;
        Node *newNode = new Node(val);
        m[node] = newNode;

        for(auto n: node->neighbors) {
            if(m.find(n) == m.end()) {
                newNode->neighbors.push_back(dfs(n));
            } else {
                newNode->neighbors.push_back(m[n]);
            }
        }

        return newNode;
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node);
    }
};
