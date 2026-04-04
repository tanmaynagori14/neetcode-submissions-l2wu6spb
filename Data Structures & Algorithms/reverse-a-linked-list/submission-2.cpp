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

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;

//         while(head) {
//             ListNode* next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }

//         return prev;
//     }
// };


class Solution {
    ListNode* fun(ListNode* head) {

        // Base case
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* front = head->next;
        // Reverse remaining list
        ListNode* newHead = fun(head->next);
    
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

public:
    ListNode* reverseList(ListNode* head) {
        return fun(head);
    }
};
