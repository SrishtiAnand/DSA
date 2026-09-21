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
    ListNode* deleteMiddle(ListNode* head) {
        int count =0;
        if(head==NULL || head->next == NULL) return NULL;
        ListNode* temp = head;
        // ListNode* temp->next = head->next;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
           for(int i = 1; i<(count/2); i++){
            temp= temp->next;
            
           }

        ListNode* middle = temp->next;
        temp->next = temp->next->next;
        delete(middle);
        return head;
    }
};
