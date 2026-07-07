class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n =arr.size();
        int ans =0;
        for(int l = 0; l<n; l++){
            int currSum = 0;
            for(int r = l; r<n; r++){
                currSum+=arr[r];
                if((r-l+1)%2!=0)
                ans+=currSum;
                
            }
        }
        return ans;
    }
};