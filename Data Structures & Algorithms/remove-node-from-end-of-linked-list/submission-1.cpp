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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f = head;
        for(int i=0 ; i<n ; i++) f = f->next;
        ListNode* s = head;

        if(f == nullptr) {
            ListNode* temp = s->next;
            delete(head);
            return temp;
        }
        
        while(f->next) {
            s = s->next;
            f = f->next;
        }

        ListNode* temp = s->next;
        s->next = temp->next;
        delete(temp);

        return head;
    }
};