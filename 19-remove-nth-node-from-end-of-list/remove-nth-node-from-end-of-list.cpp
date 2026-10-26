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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            temp = temp->next;
            len++;
        }

        len -= n;

        if (len == 0) {
            head = head->next;
        } else {
            ListNode* curr = head;

            len--;

            while (len > 0) {
                curr = curr->next;
                len--;
            }

            curr->next = curr->next->next;
        }

        return head;
    }
};
