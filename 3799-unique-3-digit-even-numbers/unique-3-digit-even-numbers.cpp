class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        unordered_set<int> s;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {

            // 1st digit cannot be 0
            if (digits[i] == 0)
                continue;

            if (vis[i] == false) {
                vis[i] = true;

                for (int j = 0; j < n; j++) {
                    if (vis[j] == false) {
                        vis[j] = true;

                        for (int k = 0; k < n; k++) {
                            if (vis[k] == false && digits[k] % 2 == 0) {

                                int num = digits[i] * 100 + digits[j] * 10 +
                                          digits[k];

                                s.insert(num);
                            }
                        }

                        vis[j] = false;
                    }
                }

                vis[i] = false;
            }
        }

        return s.size();
    }
};