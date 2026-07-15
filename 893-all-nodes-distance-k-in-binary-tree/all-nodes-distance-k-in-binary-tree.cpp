/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void markParents(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis[target] = true;

        int dist = 0;

        while (!q.empty()) {
            if (dist == k)
                break;

            int size = q.size();

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }

                // Right child
                if (curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }

                // Parent
                if (parent.count(curr) && !vis[parent[curr]]) {
                    vis[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            dist++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};