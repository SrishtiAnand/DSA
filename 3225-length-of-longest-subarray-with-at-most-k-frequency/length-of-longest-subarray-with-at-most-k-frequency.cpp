class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0; 
        int dup = 0;
        int l =0;
        int r =0;
        unordered_map<int, int> mpp;
        while(r<n){
            if(mpp[nums[r]] ==k) dup++;
            mpp[nums[r]]++;
            while(l<=r && dup>0){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==k) dup--;
                l++;
             }
             if(dup == 0) maxLen = max(maxLen, r-l+1);
             r++;
        }
        return maxLen;
    }
};