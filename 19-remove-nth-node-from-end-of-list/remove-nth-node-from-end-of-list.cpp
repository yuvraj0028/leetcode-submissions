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
    int findLength(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            cnt++;
            temp=temp->next;
        }

        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;

        ListNode* curr = head;

        int len = findLength(head);
        int removeNode = len - n;

        if(removeNode == 0) return head->next;

        for(int i = 1; i < removeNode; i++){
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};