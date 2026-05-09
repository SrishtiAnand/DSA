class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> count(n + 1, 0);

        for(int i = 0; i < trust.size(); i++) {
            
            int a = trust[i][0]; // person who trusts
            int b = trust[i][1]; // person being trusted

            count[a]--; // trusts someone → cannot be judge
            count[b]++; // gets trusted
        }

        for(int i = 1; i <= n; i++) {
            if(count[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};