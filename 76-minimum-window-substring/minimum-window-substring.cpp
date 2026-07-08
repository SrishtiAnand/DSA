class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();

        vector<vector<int>> freq(n + 1, vector<int>(70, 0));

        for (int i = 0; i < n; i++) {
            freq[i + 1][s[i] - 'A']++;

            for (int j = 0; j < 70; j++)
                freq[i + 1][j] += freq[i][j];
        }

        vector<int> tar(70, 0);

        for (int i = 0; i < m; i++)
            tar[t[i] - 'A']++;

        int val = INT_MAX;
        int ix = -1, jx = -1;

        for (int i = 1; i <= n; i++) {
            int lo = 1, hi = i;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                bool isT = true;

                for (int j = 0; j < 70; j++) {
                    int cnt = freq[i][j] - freq[mid - 1][j];

                    if (cnt < tar[j]) {
                        isT = false;
                        break;
                    }
                }

                if (isT) {
                    lo = mid + 1;

                    if (i - mid + 1 < val) {
                        val = i - mid + 1;
                        ix = mid - 1;
                        jx = i - 1;
                    }
                } else {
                    hi = mid - 1;
                }
            }
        }

        if (ix == -1)
            return "";

        return s.substr(ix, jx - ix + 1);
    }
};