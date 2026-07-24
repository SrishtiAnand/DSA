class Solution {
public:
    vector<vector<int>> f(int idx, int n) {
        if (idx > n) {
            return {{}};
        }

        vector<vector<int>> ans = f(idx + 1, n);

        int sz = ans.size();

        for (int i = 0; i < sz; i++) {
            vector<int> temp;
            temp.push_back(idx);

            for (int j = 0; j < ans[i].size(); j++) {
                temp.push_back(ans[i][j]);
            }

            ans.push_back(temp);
        }

        return ans;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> allSubsets = f(1, n);

        vector<vector<int>> ans;

        for (auto &subset : allSubsets) {
            if (subset.size() == k)
                ans.push_back(subset);
        }

        return ans;
    }
};