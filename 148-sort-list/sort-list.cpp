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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head, ListNode* head2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (head && head2) {
            if (head->val <= head2->val) {
                temp->next = head;
                head = head->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        temp->next = (head) ? head : head2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mid = findMid(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;

        head = sortList(head);
        head2 = sortList(head2);

        return merge(head, head2);
    }
};