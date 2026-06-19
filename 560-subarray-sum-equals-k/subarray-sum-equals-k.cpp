class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             int sum = 0;

//             for (int j = i; j < n; j++) {
//                 sum += nums[j];

//                 if (sum == k) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };
unordered_map<int, int> mpp;
         int sum = 0;
         int maxlen =0;
         int count = 0;
        int n = nums.size();
        mpp[0] = 1;
        for(int i=0; i<n; i++){
            sum +=nums[i];
            int rem = sum-k;
          
            count+=mpp[rem];

            mpp[sum]++;
            }

        return count;
    }
};