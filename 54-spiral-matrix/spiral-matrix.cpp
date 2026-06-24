

//         vector<int> ans;

//         int top = 0;
//         int bottom = matrix.size() - 1;
//         int left = 0;
//         int right = matrix[0].size() - 1;

//         while(top <= bottom && left <= right){

//             for(int i = left; i <= right; i++)
//                 ans.push_back(matrix[top][i]);
//             top++;

//             for(int i = top; i <= bottom; i++)
//                 ans.push_back(matrix[i][right]);
//             right--;

//             if(top <= bottom){
//                 for(int i = right; i >= left; i--)
//                     ans.push_back(matrix[bottom][i]);
//                 bottom--;
//             }

//             if(left <= right){
//                 for(int i = bottom; i >= top; i--)
//                     ans.push_back(matrix[i][left]);
//                 left++;
//             }
//         }

//         return ans;
//     }
// };
 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int i = 0, j = 0, k = 0;

        vector<vector<int>> dir = {
            {0, 1},   // Right
            {1, 0},   // Down
            {0, -1},  // Left
            {-1, 0}   // Up
        };

        vector<int> ans;

        while (true) {
            vis[i][j] = 1;
            ans.push_back(mat[i][j]);

            int ix = i;
            int jx = j;

            // Move in current direction
            ix += dir[k][0];
            jx += dir[k][1];

            // If next cell is invalid or visited, change direction
            if (ix >= n || jx >= m || ix < 0 || jx < 0 || vis[ix][jx]) {
                ix = i;
                jx = j;

                k = (k + 1) % 4;

                ix += dir[k][0];
                jx += dir[k][1];

                // If even after changing direction we can't move, we're done
                if (ix >= n || jx >= m || ix < 0 || jx < 0 || vis[ix][jx]) {
                    break;
                }
            }

            i = ix;
            j = jx;
        }

        return ans;
    }
};