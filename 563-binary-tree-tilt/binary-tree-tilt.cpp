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
int ans = 0;
int subtreeSum (TreeNode* root){
   
    if (root==NULL) return 0;
     int left = subtreeSum(root->left);
     int right = subtreeSum(root->right);
    ans+= abs(left - right);
     return root->val + left + right;
   
}
    int findTilt(TreeNode* root) {
        subtreeSum(root);
        return ans;
    }
};