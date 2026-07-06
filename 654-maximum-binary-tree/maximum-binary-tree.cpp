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
TreeNode* build(vector<int>& nums) {

    if(nums.size() == 0)
        return NULL;

    int maxi = INT_MIN;
    int index = -1;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > maxi) {
            maxi = nums[i];
            index = i;
        }
    }

    TreeNode* root = new TreeNode(maxi);

    vector<int> prefix, suffix;

    for(int i = 0; i < index; i++)
        prefix.push_back(nums[i]);

    for(int i = index + 1; i < nums.size(); i++)
        suffix.push_back(nums[i]);

    root->left = build(prefix);
    root->right = build(suffix);

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums);
}
};