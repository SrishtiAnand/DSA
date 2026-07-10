class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0;
        int r=0;
        int maxSize = 0;
        int zero = 0;
        while(r<n){
           if(nums[r]==0) k--;
           while(k<0){
            if(nums[l]==0) k++;
            l++;
           }
           maxSize = max(maxSize, r-l+1);
           r++;
        }
        return maxSize;
    }
};