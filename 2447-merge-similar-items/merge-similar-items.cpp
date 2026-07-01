class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
       map<int, int> mp;
       vector <vector<int>> arr;
       for(int i=0; i<items1.size(); i++){
        if(mp.count(items1[i][0])){
            mp[items1[i][0]]+=items1[i][1];
        }else {
         mp[items1[i][0]]=items1[i][1];
        }
        

       }

        for(int i=0; i<items2.size(); i++){
        if(mp.count(items2[i][0])){
            mp[items2[i][0]]+=items2[i][1];
        }else {
         mp[items2[i][0]]=items2[i][1];
        }
        
       }
      
       
       for (auto &it : mp) {
      arr.push_back({it.first, it.second});
      
      }

      return arr ;

    }
};