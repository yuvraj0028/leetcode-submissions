/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        int hasCycle = false;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle) return nullptr;

        slow = head;
        while(fast!=slow) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};