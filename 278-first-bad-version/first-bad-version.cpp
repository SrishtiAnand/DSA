// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
// bool isBadVersion(int n, int bad){

// }
    int firstBadVersion(int n) {
        vector<int> arr;
        int l = 1;
        int h = n;
        
        int ans =n;
        while(l<=h){
          int mid = l + (h-l)/2;

          if(!isBadVersion(mid))l = mid+1;
          else {
            ans = mid;
            h = mid -1;
          }
        }

        return ans ;
        
    }
};