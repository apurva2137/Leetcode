class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
           if(grid[i][0]==1) q.push({i,0});
           if(grid[i][m-1]==1) q.push({i,m-1});
        }
        for(int j=0;j<m;j++){
           if(grid[0][j]==1) q.push({0,j});
           if(grid[n-1][j]==1) q.push({n-1,j});
        }
        int count=0;
        while(!q.empty()){
             int r=q.front().first;
             int c=q.front().second;
             q.pop();

             int row[4]={1,0,-1,0};
             int col[4]={0,-1,0,1};
             if(grid[r][c]!=1) continue;
             grid[r][c]=0;
             for(int i=0;i<4;i++){
                int nr= r+row[i];
                int nc= c+col[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    q.push({nr,nc});
                }
             }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};