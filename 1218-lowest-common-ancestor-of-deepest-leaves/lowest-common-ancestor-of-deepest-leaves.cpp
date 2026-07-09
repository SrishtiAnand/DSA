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
    TreeNode* ans = NULL;
    int maxDepth = 0;

    int dfs(TreeNode* root, int depth) {
        if (root == NULL) {
            maxDepth = max(maxDepth, depth);
            return depth;
        }

        int leftDepth = dfs(root->left, depth + 1);
        int rightDepth = dfs(root->right, depth + 1);

        if (leftDepth == rightDepth && leftDepth == maxDepth) {
            ans = root;
        }

        return max(leftDepth, rightDepth);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};