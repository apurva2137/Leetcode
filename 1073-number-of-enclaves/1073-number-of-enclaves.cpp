class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 1) q.push({i,0});
            if(grid[i][n-1] == 1) q.push({i,n-1});
        }
        for(int j = 0 ; j < n ; j++){
            if(grid[0][j] == 1) q.push({0,j});
            if(grid[m-1][j] == 1) q.push({m-1,j});
        }

        int row[4] = {-1 , 0 , 1 , 0};
        int col[4] = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            grid[r][c] = INT_MAX;

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + row[i];
                int nc = c + col[i];
    
                if(nr >= 0 && nr < m && nc >= 0 && nc < n 
                   && grid[nr][nc] == 1){
                      grid[nr][nc] = INT_MAX;
                      q.push({nr , nc});
                }
            }
        }
        int count = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};