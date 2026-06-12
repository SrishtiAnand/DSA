class Solution {
public:

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for( int i = 1; i<n; i++ ){
            
            if(nums[i]==nums[i-1]){
                // result.push_back(nums[i]);
                result.push_back(nums[i]);
                
            }
        }
        return result;
    }
};