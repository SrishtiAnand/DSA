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
vector<int> arr;
TreeNode* prev = NULL;
int currCount =0;
int maxCount =0;
void f(TreeNode* root){
    if(root==NULL) return;
    f(root->left);
    if(prev!=NULL && prev->val == root->val)
        currCount++;
    else
        currCount = 1;
    
    if(currCount>maxCount){
        maxCount = currCount;
        arr.clear();
        arr.push_back(root->val);
    }
    else if(currCount==maxCount){
        arr.push_back(root->val);
    }
    prev=root;
    f(root->right);
};

    vector<int> findMode(TreeNode* root) {
        f(root);
        return arr;
    }
};