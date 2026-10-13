class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        int val = 1;
        long ans=0;
        long frontSum =0;
        long endSum =0;
        for(int i=0; i<n; i++){
          val = nums[i]*nums[i];
          arr.push_back(val);
          
        }
        sort(arr.begin(), arr.end());
        int mid = n/2;
            for(int i=0; i<mid; i++){
                frontSum += arr[i];
            }
            for(int i=mid; i<n; i++){
                endSum += arr[i];
        }
ans = endSum - frontSum;
        
return ans;
    }
};