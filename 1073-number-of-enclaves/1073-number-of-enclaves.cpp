class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
       int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 1) q.push({i,0});
            if(board[i][n-1] == 1) q.push({i,n-1});
        }
        for(int j = 0 ; j < n ; j++){
            if(board[0][j] == 1) q.push({0,j});
            if(board[m-1][j] == 1) q.push({m-1,j});
        }
        int row[4] = {-1, 0 , 1 , 0};
        int col[4] = {0, -1 , 0 , 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(board[r][c]!=1) continue;
            board[r][c] = 0;

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m &&
                 nc >= 0 && nc < n && board[nr][nc] ==1 ){
                    q.push({nr,nc});
                }
            } 
        }
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j <  n ; j++){
              if(board[i][j] == 1) count++;
            }
        }
        return count;
    }
};