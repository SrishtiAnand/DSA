class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        int m = points.size();
        int minArea = INT_MAX;

        for (int i = 0; i < m; i++) {

            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < m; j++) {

                int x2 = points[j][0];
                int y2 = points[j][1];

               
                if (x1 == x2 || y1 == y2)
                    continue;

                bool p1 = false;
                bool p2 = false;

                for (int k = 0; k < m; k++) {

                    if (points[k][0] == x1 && points[k][1] == y2)
                        p1 = true;

                    if (points[k][0] == x2 && points[k][1] == y1)
                        p2 = true;
                }

                if (p1 && p2) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    minArea = min(minArea, area);
                }
            }
        }

        if (minArea == INT_MAX)
            return 0;

        return minArea;
    }
};