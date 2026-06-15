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
private:
    ListNode* getNodeBeforeMiddle(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = curr;
        ListNode* next = head;

        while(curr->next && next->next) {
            prev = curr;
            curr = curr->next;
            next = next->next;
            if(next->next) next = next->next;
        }

        return prev;
    }

public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;

        ListNode* node = getNodeBeforeMiddle(head);
        node->next = node->next->next;
        return head;
    }
};