class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        deque<int> maxi, mini;

        int left = 0;
        int n = nums.size();

        long long ans = 0;

        for(int right = 0; right < n; right++) {

            while(!maxi.empty() && nums[maxi.back()] < nums[right]) {
                maxi.pop_back();
            }

            maxi.push_back(right);

            while(!mini.empty() && nums[mini.back()] > nums[right]) {
                mini.pop_back();
            }

            mini.push_back(right);

            while(nums[maxi.front()] - nums[mini.front()] > 2) {

                left++;

                if(maxi.front() < left) {
                    maxi.pop_front();
                }

                if(mini.front() < left) {
                    mini.pop_front();
                }
            }

            ans += right - left + 1;
        }

        return ans;
    }
};