class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
            int cnt =0;
            for(int i=0; i<n; i++){
               for(int j=0; j<n; j++){
                if(i<j && nums[i]==nums[j] && (i*j)%k==0){
                    cnt++;
                }
               }
            }
        
        return cnt;
    }
};