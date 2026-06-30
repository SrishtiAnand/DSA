class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

multimap<int, vector<int>> mp;

for(auto &p : points){
    int dist = p[0]*p[0] + p[1]*p[1];
    mp.insert({dist, p});
}
vector<vector<int>> ans;

int cnt = 0;
for(auto &it : mp){
    ans.push_back(it.second);
    cnt++;
    if(cnt == k) break;
}
return ans;
    }
};