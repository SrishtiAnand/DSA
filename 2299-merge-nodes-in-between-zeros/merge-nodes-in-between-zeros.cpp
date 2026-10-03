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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int sum =0;
        while(right!=NULL){
            if(right->val!=0){
                sum+=right->val;
            }else{
                curr->next = new ListNode(sum);
                curr = curr->next;
                sum =0;
                left = right;
            }
            right = right->next;
        }

return ans->next;

        
    }
};