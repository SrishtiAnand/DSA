class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        vector<int> prefix(n+1);
        vector<int> suffix(n+1);
        prefix[0] = 0;
        for(int i=0; i<n; i++){
           prefix[i+1] = prefix[i] + cardPoints[i];
        }for(int i=n-1; i>=0; i--){
            suffix[i] = suffix[i+1]+ cardPoints[i];
        }
        for(int i = 0; i<=k; i++){
            int left = prefix[i];
            int right = suffix[n-(k-i)];
            ans = max(ans, left + right);
        }
        return ans;
    }
};