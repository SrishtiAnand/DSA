class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
     int i=0;
     if(n<3){
        return -1;
     }
        return nums[i+1];
    }
};