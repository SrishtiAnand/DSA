class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        //     int minNum = INT_MAX;
        //     int maxNum  = INT_MIN;
        //    for(int i=0; i<=n-i; i++){
        //     for(int j=i; j<n; j++){
        //         if(nums[j]<minNum){
        //             minNum = nums[j];
        //         }
        //         if(nums[i]>maxNum){
        //             maxNum = nums[i];
        //         }
        //         if(maxNum-minNum <= k)
        //         return i;
        //     }
        //    }
        //    return -1;
        vector<int> maxA(n);
        vector<int> minA(n);
        
        maxA[0] = nums[0];
        

        minA[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            maxA[i] = max(maxA[i - 1], nums[i]);
        }

        for (int j = n - 2; j >= 0; j--) {
            minA[j] = min(minA[j+1], nums[j]);
        }

        for (int i = 0; i < n; i++) {
            if (maxA[i] - minA[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};