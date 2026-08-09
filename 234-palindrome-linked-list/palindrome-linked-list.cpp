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
    bool isListPalindrome = true;
    ListNode* recCurr = nullptr;

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

    bool checkPalindromeStack(ListNode* head) {
        if(!head || !head->next) return head;

        stack<ListNode*> st;
        ListNode* curr = head;
        
        while(curr){
            st.push(curr);
            curr = curr->next;
        }

        int k = st.size() / 2;
        while(k--) {
            ListNode* top = st.top();
            st.pop();

            if(head->val != top->val) {
                return false;
            }

            head = head->next;
        }

        return true;
    }

    void checkPalindromeRecursion(ListNode* head) {
        if(!head){
            return;
        }

        checkPalindromeRecursion(head->next);

        if(head->val != recCurr->val) {
            isListPalindrome = false;
            return;
        }

        recCurr = recCurr->next;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        // ListNode* curr = head;
        // ListNode* middle = getMiddle(curr);
        // ListNode* rev = reverseList(middle);

        // while(head && rev) {
        //     if(head->val != rev->val) {
        //         return false;
        //     }

        //     head = head->next;
        //     rev = rev->next;
        // }

        // return true;

        // return checkPalindromeStack(head);

        recCurr = head;
        checkPalindromeRecursion(head);
        
        return isListPalindrome;
    }
};