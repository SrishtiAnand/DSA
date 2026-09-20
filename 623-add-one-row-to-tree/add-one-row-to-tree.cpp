/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        if(root == NULL) return NULL;

        if(depth == 2) {
            TreeNode* Left = new TreeNode(val);
            TreeNode* Right = new TreeNode(val);

            Left->left = root->left;
            Right->right = root->right;

            root->left = Left;
            root->right = Right;

            return root;
        }

        addOneRow(root->left, val, depth - 1);
        addOneRow(root->right, val, depth - 1);

        return root;
    }
};