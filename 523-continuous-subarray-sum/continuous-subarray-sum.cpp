class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Remainder 0 occurs before the array starts
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem = sum % k;

            // Handle negative numbers (optional for this problem)
            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end()) {
                // Subarray length should be at least 2
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }

        return false;
    }
};