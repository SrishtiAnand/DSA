class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
      for(int i=0; i<n; i++){
        int maxVal = -1;
        for(int j=i+1; j<n; j++){
            maxVal = max(maxVal, arr[j]);
            
        }
        arr[i]= maxVal;
      }
        return arr;
    }
};