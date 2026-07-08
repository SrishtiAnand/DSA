class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        long totalSum = 0;
        long minDiff = LONG_MAX;
        for (int x: nums)
            totalSum+=x;
            long leftSum = 0;
        
for(int i=0; i<n; i++){
    leftSum += nums[i];
    long rightSum= totalSum - leftSum;
    long leftAvg = leftSum/(i+1);
    long rightAvg = 0;
    if(i!=n-1)
    rightAvg = rightSum/(n-i-1);
    long diff = abs(leftAvg - rightAvg);
    if(diff<minDiff){
        minDiff= diff;
        ans=i;
    }

        }
        return ans;
    }
};