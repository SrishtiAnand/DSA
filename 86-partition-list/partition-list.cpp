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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = new ListNode(0);
        ListNode* dummy1 = dummy;
        ListNode* curr1 = curr;
       
        while(temp!=NULL){
            if(temp->val<x){
            dummy1->next = temp;
            dummy1 = dummy1->next;

            }else{
               curr1->next = temp;
               curr1 = curr1->next;
            }
            temp = temp->next;
        }
        curr1->next=NULL;
        dummy1->next = curr->next;
        return dummy->next;
    }
};