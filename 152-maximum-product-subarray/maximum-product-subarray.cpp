class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < 0)
                swap(maxEnding, minEnding);

            maxEnding = max(nums[i], nums[i] * maxEnding);
            minEnding = min(nums[i], nums[i] * minEnding);

            ans = max(ans, maxEnding);
        }

        return ans;
    }
};