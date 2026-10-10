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
    ListNode* doubleIt(ListNode* head) {
        if(head == NULL) return NULL;

        vector<int> arr;
        ListNode* temp = head;

        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int carry = 0;

        for(int i = arr.size()-1; i >= 0; i--) {
            int val = arr[i] * 2 + carry;
            arr[i] = val % 10;
            carry = val / 10;
        }

        if(carry > 0) {
            arr.insert(arr.begin(), carry);
        }

        ListNode* dummy = new ListNode(0);
        temp = dummy;

        for(int i = 0; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return dummy->next;
    }
};