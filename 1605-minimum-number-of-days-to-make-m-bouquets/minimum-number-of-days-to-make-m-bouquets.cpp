class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();

        int l = *min_element(b.begin(), b.end());
        int h = *max_element(b.begin(), b.end());

        if ((long long)m * k > n)
            return -1;

        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            int cnt = 0;
            int bouquet = 0;

            for (int i = 0; i < n; i++) {
                if (b[i] <= mid) {
                    cnt++;
                } else {
                    bouquet += cnt / k;
                    cnt = 0;
                }
            }

            bouquet += cnt / k;

            if (bouquet >= m) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};