
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int len = 0;
        int maxFreq = 0;

        unordered_map<char, int> mp;

        while (r < n) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            while ((r - l + 1) - maxFreq > k) {
                mp[s[l]]--;
                l++;
            }

            len = max(len, r - l + 1);
            r++;
        }

        return len;
    }
};
