class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        int n = l.size();
        int lo = 0;
        int hi = n-1;
        int ans = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(l[mid]>target){
                ans = mid;
                hi = mid-1;
            }else{
                lo =mid+1;
            }
        }
        return l[ans];
    }
};