class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int z=0; int t = nums.size()-1;
        while(i<=t){
            if(nums[i]==0){
                 swap(nums[i], nums[z]);
                 z++;
                 i++;
            }
            else if(nums[i]==2){
                 swap(nums[i], nums[t]);
                 t--;
            }else
            i++;
        }
    }
};                    