class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
       sort(nums.begin(), nums.end());
       for(int i = 0; i<n && k>0; i++){
        if(nums[i]<0){
            nums[i]=-nums[i];
            k--;
        }
       }
       int mini = nums[0];
       int sum =0;
       for(int i=0; i<n; i++){
          mini = min(mini, nums[i]);
          sum+=nums[i];
       }
       if(k%2==1){
        sum -= 2*mini;
       }
       return sum;
    }
};