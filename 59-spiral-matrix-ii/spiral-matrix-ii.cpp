class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    //    int  = mat.size();
        // int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(n, 0));

        int i = 0, j = 0, k = 0;

        vector<vector<int>> dir = {
            {0, 1},  
            {1, 0},   
            {0, -1},  
            {-1, 0}  
        };

       vector<vector<int>> mat(n, vector<int>(n,0));
       int num =1;

        while (true) {
            vis[i][j] = 1;
            mat[i][j]= num++;

            int ix = i;
            int jx = j;

            
            ix += dir[k][0];
            jx += dir[k][1];

            
            if (ix >= n || jx >= n || ix < 0 || jx < 0 || vis[ix][jx]) {
                ix = i;
                jx = j;

                k = (k + 1) % 4;

                ix += dir[k][0];
                jx += dir[k][1];
                if (ix >= n || jx >= n || ix < 0 || jx < 0 || vis[ix][jx]) {
                    break;
                }
            }

            i = ix;
            j = jx;
        }

        return mat;
    }
};