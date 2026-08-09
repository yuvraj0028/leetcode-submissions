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
        
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* getMiddle(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* curr = head;
        ListNode* start = head;
        ListNode* middle = getMiddle(curr);
        ListNode* end = reverseList(middle->next);
        middle->next = nullptr;

        while(end) {
            ListNode* temp1 = start->next;
            ListNode* temp2 = end->next;

            start->next = end;
            end->next = temp1;

            start = temp1;
            end = temp2;
        }
    }
};