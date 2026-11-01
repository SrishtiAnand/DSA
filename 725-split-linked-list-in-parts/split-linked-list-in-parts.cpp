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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        int partSize = len / k;
        int extra = len % k;

        vector<ListNode*> ans(k, NULL);
        temp = head;

        for(int i = 0; i < k; i++) {
            ans[i] = temp;

            int size = partSize;
            if(extra > 0) {
                size++;
                extra--;
            }

            for(int j = 1; j < size; j++) {
                if(temp != NULL) {
                    temp = temp->next;
                }
            }

            if(temp != NULL) {
                ListNode* nextNode = temp->next;
                temp->next = NULL;
                temp = nextNode;
            }
        }

        return ans;
    }
};