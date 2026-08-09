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
    int cnt;
    ListNode* removeHelper(ListNode* head, int n) {
        if(!head) return nullptr;

        head->next = removeHelper(head->next, n);
        cnt++;

        if(cnt == n) {
            return head->next;
        }
        return head;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return nullptr;

        cnt = 0;
        ListNode* curr = head;
        head = removeHelper(curr, n);
        
        return head;
    }
};