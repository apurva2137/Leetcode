class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][n-1] == 'O') q.push({i,n-1});
        }
        for(int j = 0 ; j < n ; j++){
            if(board[0][j] == 'O') q.push({0,j});
            if(board[m-1][j] == 'O') q.push({m-1,j});
        }
        int row[4] = {-1, 0 , 1 , 0};
        int col[4] = {0, -1 , 0 , 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            board[r][c] ='#';

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m &&
                 nc >= 0 && nc < n && board[nr][nc] =='O' ){
                    q.push({nr,nc});
                    board[nr][nc] = '#';
                }
            } 
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j <  n ; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};