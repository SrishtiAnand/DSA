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
    vector<long long> arr;

    void dfs(TreeNode* root, int depth) {
        if (root == NULL) return;

        if (depth == arr.size()) {
            arr.push_back(0);
        }

        arr[depth] += root->val;

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);

        sort(arr.begin(), arr.end());

        if (k > arr.size()) {
            return -1;
        }

        return arr[arr.size() - k];
    }
};