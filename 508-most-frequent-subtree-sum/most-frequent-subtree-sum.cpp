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
int subtreeSum(TreeNode* root){
   
    if(root==NULL) return 0;
    int left = subtreeSum(root->left);
    int right = subtreeSum(root->right);
    int sum = root->val+left+right;
    arr.push_back(sum);
    return sum;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
       subtreeSum(root);
       unordered_map<int, int> mp;

        int maxFreq = 0;

        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
            maxFreq = max(maxFreq, mp[arr[i]]);
        }

        vector<int> ans;

        for(auto it : mp) {
            if(it.second == maxFreq) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};