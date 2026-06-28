class Solution {
public:
int sumdigit(int num){
    int sum =0;
     while(num!=0){
        int digit = num%10;
        sum+=digit;
        num/=10; 
        }
        return sum;
}
    int countLargestGroup(int n) {
       unordered_map<int, int> mp;
       for(int i=1; i<=n; i++){
        int sum = sumdigit(i);
        mp[sum]++;
       } int maxSum = 0;
       for(auto it: mp){
        maxSum  = max(maxSum, it.second);
       }int ans =0;
       for(auto it: mp){
        if(it.second == maxSum)
        ans++;
       }
       return ans;
    }
};