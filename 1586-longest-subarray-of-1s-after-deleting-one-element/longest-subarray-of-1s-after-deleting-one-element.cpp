class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int zero=0;
        int r = 0;
        int size = 0;
        int maxSize =0;
        while(r<n){
        if(nums[r]==0)
        zero++;
        if(zero>1){

           if(nums[l]==0)
          zero--;
          l++;
            
        }
        maxSize=max(maxSize, r-l);
       r++;
        }
        return maxSize;
    }
};