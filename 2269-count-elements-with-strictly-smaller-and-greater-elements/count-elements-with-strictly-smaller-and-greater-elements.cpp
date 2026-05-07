class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
           if(nums[i] > nums[0] && nums[i] < nums[nums.size()-1]) {
            count++;
           }
        }
        return count;
    }
};