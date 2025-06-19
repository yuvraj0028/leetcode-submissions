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
    ListNode* findMid(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next){
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right){
        if(!left) return right;
        if(!right) return left;
        if(!left && !right) return NULL;

        ListNode* dummyNode = new ListNode(0);
        ListNode* result = dummyNode;

        while(left && right){
            if(left->val < right->val){
                result->next = left;
                left = left->next;
                result = result->next;
            } else {
                result->next = right;
                right = right->next;
                result = result->next;
            }
        }

        while(left){
            result->next = left;
            left = left->next;
            result = result->next;
        }

        while(right){
            result->next = right;
            right = right->next;
            result = result->next;
        }

        return dummyNode->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        ListNode* left = head;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        
        ListNode* result = mergeList(left, right);
        return result;
    }
};