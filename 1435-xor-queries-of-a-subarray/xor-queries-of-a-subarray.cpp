class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n+1);
        prefix[0] = 0;
        for(int i=1; i<=n; i++){
          prefix[i]=prefix[i-1]^arr[i-1];
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i<m ; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i]= prefix[r+1]^prefix[l];
        }
        return ans;
    }
};