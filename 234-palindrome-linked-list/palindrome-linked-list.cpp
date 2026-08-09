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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
    
        ListNode* newNode = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return newNode;
    }

    ListNode* getMiddle(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* middle = getMiddle(curr);
        ListNode* rev = reverseList(middle);

        while(head && rev) {
            if(head->val != rev->val) {
                return false;
            }

            head = head->next;
            rev = rev->next;
        }

        return true;
    }
};