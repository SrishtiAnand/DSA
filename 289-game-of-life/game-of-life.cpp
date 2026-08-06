class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>> q;

        // Push all cells into the queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                q.push({i, j});
            }
        }

        // First pass
        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            int live = 0;

            for(int k = 0; k < 8; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   abs(board[nr][nc]) == 1) {
                    live++;
                }
            }

            if(board[r][c] == 1) {
                if(live < 2 || live > 3)
                    board[r][c] = -1;   // Alive -> Dead
            }
            else {
                if(live == 3)
                    board[r][c] = 2;    // Dead -> Alive
            }
        }

        // Second pass
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};