class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        int sum =0;
        int val = 1;
        for(int i=0; i<n; i++){
            if(n%(i+1)==0){
                val = nums[i]*nums[i];
                arr.push_back(val);
            }
        }
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
        }
        return sum;
    }
};