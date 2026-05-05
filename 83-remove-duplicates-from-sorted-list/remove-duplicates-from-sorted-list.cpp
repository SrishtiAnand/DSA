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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr_node = head;
        while(curr_node!=NULL){
            while(curr_node->next && curr_node->val == curr_node->next->val){
                ListNode* temp = curr_node->next;
                curr_node->next = curr_node->next->next;
                delete temp;
            }
            curr_node = curr_node->next;
        }
        return head;
    }
};