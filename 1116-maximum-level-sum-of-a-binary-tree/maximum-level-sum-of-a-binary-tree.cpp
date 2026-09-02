/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    
    class Pair {
        public:
        TreeNode* node ;
        int level;

        Pair(TreeNode *node , int level){
            this->node  = node ;
            this->level = level;
        }
    };
public:
    int maxLevelSum(TreeNode* root) {

        queue<Pair> q;

        int size = q.size();
        int sum = INT_MIN;
        int lev = 1;
        q.push(Pair(root, 1));
        while (q.size() > 0) {
            int size = q.size();
            int s = 0;
            int l = 0;

            for (int i = 0; i < size; i++) {
                Pair curr = q.front();
                q.pop();
                s += curr.node->val;
                l = curr.level;
                if (curr.node->left != NULL)
                    q.push( Pair (curr.node->left, curr.level+1));
                if (curr.node->right != NULL)
                    q.push(Pair (curr.node->right, curr.level+1));
            }

            if (s > sum) {
                sum = s;
                lev = l;
            }
        }

        return lev;
    }
};