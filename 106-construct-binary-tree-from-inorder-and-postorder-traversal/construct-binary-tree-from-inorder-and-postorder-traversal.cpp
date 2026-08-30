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

    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTreeHelper(vector<int>& inorder,
                              vector<int>& postorder,
                              int& postIdx,
                              int left,
                              int right) {

        // No elements in this range
        if (left > right) {
            return NULL;
        }

        // Last element of postorder is root
        int rootVal = postorder[postIdx];
        postIdx--;

        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int inIdx = search(inorder, left, right, rootVal);

        // IMPORTANT: Build right first
        root->right = buildTreeHelper(inorder, postorder,
                                       postIdx, inIdx + 1, right);

        root->left = buildTreeHelper(inorder, postorder,
                                      postIdx, left, inIdx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postIdx = postorder.size() - 1;

        return buildTreeHelper(inorder, postorder,
                               postIdx, 0, inorder.size() - 1);
    }
};