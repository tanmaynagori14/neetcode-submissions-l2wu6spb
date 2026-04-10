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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* head = new ListNode(-1);
        ListNode* dummyhead = head;
        for(auto it: lists) {
            pq.push({it->val, it});
        } 

        while(!pq.empty()) {
            ListNode* node = pq.top().second;
            pq.pop();
            ListNode* nextNode = node->next;
            if(nextNode != nullptr) pq.push({nextNode->val, nextNode});
            head->next = node;
            head = head->next;
            head->next = nullptr;
        }

        return dummyhead->next;
    }
};
