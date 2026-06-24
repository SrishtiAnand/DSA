class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//             int maxCount = 0;
//         // vector<int> arr;
//         for(int i =0; i<n; i++){
//             // int count = 0;
//             // int maxCount = 0;
//             if(nums[i]==1){
//                 count++;
//                 maxCount= max(maxCount, count);
//             }else{
//                 count = 0;
//             }
//         }
//         return maxCount;
//     }
// };
int n =nums.size();
int l = 0;
 int r= 0;
 int count =0;
 while(r<n){
    if(nums[r]==0){
       l=r+1;
    }
    count=max(count ,r-l+1);
    r++;
 }
   return count;
    }
};