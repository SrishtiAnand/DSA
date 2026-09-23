class Solution {
public:
int f(vector<int>& nums, int k){
    int maxlen = 0;
        int count =0;
        int odd = 0;
        int n = nums.size();
        int l = 0;
        for(int r=0; r<n; r++){
            if(nums[r]%2!=0)
             odd++;
            
        
           while(odd>k){
            if(nums[l]%2!=0)
                odd--;
                l++;
            
           }
           count+=(r-l+1);
        }
       
        return count;
    
}
    int numberOfSubarrays(vector<int>& nums, int k) {
       return f(nums, k)- f(nums, k-1);
    }
};