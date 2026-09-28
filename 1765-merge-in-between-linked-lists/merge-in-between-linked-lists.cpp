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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list1==NULL || list2==NULL) return NULL;
        ListNode* dummy = new ListNode(-1, list1);
       ListNode* prev = dummy;
       for(int i=0; i<a; i++){
        prev = prev->next;
       }
       ListNode* temp = prev;
       for(int i=a; i<=b; i++){
        temp= temp->next;
       }
       temp = temp->next;
     prev->next=list2;
     ListNode* curr = list2;
     while(curr->next!=NULL){
     curr = curr->next;
    //  curr->next=temp->next;
     }
     curr->next=temp;
       
     return dummy->next;
    }
};