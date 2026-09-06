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
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL)
            return NULL;

        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp!=NULL){
            while(!st.empty() && st.top()->val<temp->val){
                st.pop();
            }
            st.push(temp);
            temp = temp->next;
        }
        ListNode* newHead = st.top();
        st.pop();
        ListNode* curr = newHead;
        while(!st.empty()){
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        curr->next = NULL;
         ListNode* prev = NULL;
        curr = newHead;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};