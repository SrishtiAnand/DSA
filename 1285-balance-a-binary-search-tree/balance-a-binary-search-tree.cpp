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
public:
    vector<int> arr;
    void f(TreeNode* root) {
        if (root == NULL)
            return;
        f(root->left);
        arr.push_back(root->val);
        f(root->right);
    }
    TreeNode* middle(vector<int>& arr, int l, int h) {
        if (l > h)
            return NULL;
        int mid = (l + h) / 2;
        TreeNode* newRoot = new TreeNode(arr[mid]);
        newRoot->left = middle(arr, l, mid - 1);
        newRoot->right = middle(arr, mid + 1, h);
        return newRoot;
    }
    TreeNode* balanceBST(TreeNode* root) {
        f(root);
        return middle(arr, 0, arr.size() - 1);
    }
};