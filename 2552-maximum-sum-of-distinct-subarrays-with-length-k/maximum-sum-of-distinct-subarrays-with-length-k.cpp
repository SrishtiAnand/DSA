class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        int l =0 ;
        int r = 0;
        long sum =0;
        int dup = 0;
        long maxSum = 0;
        unordered_map<int, int> mpp;
        while(r<n){
            sum+=nums[r];
            if(mpp[nums[r]] ==1) dup++;
            mpp[nums[r]]++;
            while(l<=r && (dup>0 || r-l+1 >k)){
                 sum-=nums[l];
                mpp[nums[l]]--;
                 if(mpp[nums[l]] == 1) dup--;
                 l++;
            }
             if(r-l+1==k && dup==0){
                maxSum = max(maxSum,  sum);
             }
             r++;
        }
        return maxSum;
    }
};