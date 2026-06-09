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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while(!q.empty()) {
            int currLevelsize = q.size();
            long long stIdx = q.front().second;
            long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for(int i = 0; i < currLevelsize; i++) {
                auto curr = q.front();
                q.pop();

                long long idx = curr.second - stIdx; // normalize

                if(curr.first->left) {
                    q.push({curr.first->left, idx * 2 + 1});
                }

                if(curr.first->right) {
                    q.push({curr.first->right, idx * 2 + 2});
                }
            }
        }

        return maxWidth;
    }
};