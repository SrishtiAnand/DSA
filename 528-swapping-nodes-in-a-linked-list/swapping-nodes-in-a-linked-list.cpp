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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode* x = head;
        ListNode* y = head;
        for(int i=1; i<k; i++){
            x = x->next;
        }
        ListNode* temp = x;
        while(temp->next!=NULL){
            temp=temp->next;
            y = y->next;
        }
        swap(x->val, y->val);
        return head;
    }
};