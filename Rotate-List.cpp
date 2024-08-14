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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;

        ListNode *temp = head;

        if(!head || head->next == NULL){
            return head;
        }

        while(temp){
            count++;
            temp = temp->next;
        }
        k = k%count;
        if(k == 0){
            return head;
        }

        int newCount = count-k;

        ListNode *prev = NULL;
        ListNode *current = head;
        while(newCount--){
            prev = current;
            current = current->next;
        }
        prev->next = NULL;

        ListNode *tail = current;

        while(tail->next!=NULL){
            tail = tail->next;
        }
        tail->next = head;
        
        head = current;
        return head;

    }
};
