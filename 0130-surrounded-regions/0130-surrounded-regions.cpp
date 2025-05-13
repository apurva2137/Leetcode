class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][m-1] == 'O') q.push({i, m-1});
        }
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') q.push({0, j});
            if(board[n-1][j] == 'O') q.push({n-1, j});
        }
        int row[4]={1,0,-1,0};
        int col[4]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            board[r][c]='#';
            for(int i=0;i<4;i++){
                int nr= r +row[i];
                int nc= c+ col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O'){
                    q.push({nr,nc});
                    board[nr][nc]='#';
                }
            }
        } 
        for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '#') board[i][j]='O';
            else if(board[i][j] == 'O') board[i][j]='X';
        }
        }
    }
};