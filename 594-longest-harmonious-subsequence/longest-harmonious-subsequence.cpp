class Solution {
public:
    int findLHS(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0;
        int ans = 0;
        int r= 0;

       while(r<n) {

            while (nums[r] - nums[l] > 1) {
                l++;
            }
            

            if (nums[r] - nums[l] == 1) {
                ans = max(ans, r - l + 1);
            }
            r++;
        }

        return ans;
    }
};