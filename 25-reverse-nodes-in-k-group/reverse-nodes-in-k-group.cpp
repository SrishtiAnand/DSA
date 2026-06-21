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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k)
            return head;

        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        int counter =0;
        while(currptr!=NULL & counter < k){
             ListNode* nextptr = currptr->next;
             currptr->next = prevptr;
             prevptr = currptr;
             currptr = nextptr;
             counter++;
        }
        if(currptr!=NULL){
            ListNode* new_head = reverseKGroup(currptr, k);
            head->next = new_head;
        };
        return prevptr;
    }
    
};