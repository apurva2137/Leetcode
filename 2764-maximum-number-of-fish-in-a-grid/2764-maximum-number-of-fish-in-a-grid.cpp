class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxcount = 0;
            
        queue<pair<int,int>> q;

        for(int i = 0 ; i <m ; i++ ){
            for(int j = 0 ; j < n ; j++ ){

                if(grid[i][j] != 0)  {
                    q.push({i,j});
                    int count = 0;
                    int row[4] = {-1 , 0 , 1 , 0};
                    int col[4] = {0 , -1 , 0 , 1};
        
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        count += grid[r][c];
                        grid[r][c] = 0;
                        for(int i = 0 ; i < 4 ; i++){
                            int nr = r + row[i];
                            int nc = c + col[i];
                            
                            if(nr >= 0 && nr < m &&  nc >= 0 && nc < n &&
                            grid[nr][nc] != 0 ){
                                q.push({nr,nc});
                            }
                        }
                    }
                    maxcount = max(maxcount , count);
                }
            }
        }
        return maxcount;
    }
};