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
int x ;
 pair<int, int> sum(TreeNode* root, int count) {
   
    if(root==NULL) return {0,0};
    
    pair<int, int> left = sum(root->left, count+1);
    pair<int, int> right = sum (root->right, count+1);
    int sum = root->val + left.first + right.first;
      count =  1+ left.second + right.second;
    int avg = sum/count;
    if(avg==root->val){
        x++;
    }
    return {sum, count};
 };
    int averageOfSubtree(TreeNode* root) {
       x=0;
        sum(root, 1);
       
        return x;
    }
};