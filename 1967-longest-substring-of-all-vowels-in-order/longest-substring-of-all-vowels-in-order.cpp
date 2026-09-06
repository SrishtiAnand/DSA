class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l = 0;
         int r = 0;
         int ans =0;
         for(int r=0; r<n; r++){
            mp[s[r]]++;
            while(r>l && s[r]<s[r-1]){
                mp[s[l]]--;
                 if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }

                l++;
            }
            if(mp.size()==5){
                ans = max(ans, r-l+1);
            }
         }
         return ans;
    }
};