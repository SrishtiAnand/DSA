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
    long long totalSum = 0;
    long long maxProd = 0;

    long long findSum(TreeNode* root) {
        if(root == NULL) return 0;

        return root->val +
               findSum(root->left) +
               findSum(root->right);
    }

    long long solve(TreeNode* root) {
        if(root == NULL) return 0;

        long long left = solve(root->left);
        long long right = solve(root->right);

        long long sum = root->val + left + right;

        long long product = sum * (totalSum - sum);

        maxProd = max(maxProd, product);

        return sum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = findSum(root);

        solve(root);

        return maxProd % 1000000007;
    }
};