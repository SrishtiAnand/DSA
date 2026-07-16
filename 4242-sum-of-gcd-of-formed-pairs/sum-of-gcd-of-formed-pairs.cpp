#include <numeric>
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxN = INT_MIN;
        vector<int> ans;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            maxN = max(maxN, nums[i]);
            ans.push_back(std::gcd(nums[i], maxN));
        }

        sort(ans.begin(), ans.end());

        int l = 0, r = n - 1;
        while (l < r) {
            sum += std::gcd(ans[l], ans[r]);
            l++;
            r--;
        }

        return sum;
    }
};