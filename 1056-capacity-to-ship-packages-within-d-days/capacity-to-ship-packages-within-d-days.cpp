class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {

         int n = w.size();
        int low =0, high=0;
        int mid =0;
        for(int i=0; i<n; i++){
            low = max(low,w[i]);
            high+=w[i];
        }
        int ans =high;
            while(low<=high){
             mid = low+(high-low)/2;
             
        int requiredDays = 1;
        int currentWeight = 0;
        for (int weight : w) {
         if (currentWeight + weight <= mid) {
          currentWeight += weight;
    }     else {
         requiredDays++;
         currentWeight = weight;
    }
}
           if(requiredDays<=days){
            ans =requiredDays;
           high =mid-1;
            }else low =mid+1;

            }
            return low;
    }
};