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
    ListNode* findKthNode(ListNode* node, int k) {
        if(!node) return nullptr;

        k--;
        ListNode* kthNode = node;
        while(kthNode && k) {
            kthNode=kthNode->next;
            k--;
        }

        return kthNode;
    }

    ListNode* reverseList(ListNode* node) {
        if(!node) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = node;

        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp) {
            ListNode* kthNode = findKthNode(temp,k);
            
            if(kthNode == nullptr) {
                if(prev) prev->next = temp;
                break;
            }

            ListNode* nextHead = kthNode->next;
            kthNode->next = nullptr;
            reverseList(temp);

            if(temp == head) {
                head = kthNode;
            } else {
                if(prev){
                    prev->next = kthNode;
                }
            }

            prev = temp;
            temp = nextHead;
        }

        return head;
    }
};