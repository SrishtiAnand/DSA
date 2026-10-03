class Solution {
public:
    int arrangeCoins(int n) {
        long l = 1;
        long h = n;
        while(l<=h){
        long mid = l+(h-l)/2;
        long  ans = mid*(mid+1)/2;
        if(ans==n) return mid;
        else if(ans<n) l = mid+1;
        else h = mid-1;
        }
        return l-1;
    }
};