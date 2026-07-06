class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(points.empty())
        return 0;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
        });
        int arrows = 1;
        int arrPos = points[0][1];
        for(int i = 0; i< n ;i++){
            if(points[i][0]>arrPos){
                arrows++;
                arrPos = points[i][1];
            }
        }
        return arrows;
    }
};