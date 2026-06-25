class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int r=0;
        int count = 0;

        unordered_map<char, int> mpp;

       while(r<n) {
            mpp[s[r]]++;

            while (l<=r && mpp.size() == 3) {
                count += (n - r);

                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);

                l++;
            }
            r++;
        }

        return count;
    }
};