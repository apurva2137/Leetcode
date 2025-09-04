class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) q.push({i,j});
                else grid[i][j] = INT_MAX;
            }
        }
        int row[4] = {-1 , 0 , 1 , 0};
        int col[4] = {0 , 1 , 0 , -1};


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                 grid[nr][nc] > grid[r][c]){
                   grid[nr][nc] = grid[r][c] + 1;
                   q.push({nr,nc});
                }
            }
        }
        return grid;
    }
};