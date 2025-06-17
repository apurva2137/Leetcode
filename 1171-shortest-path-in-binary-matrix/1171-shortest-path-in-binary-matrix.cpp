class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));
        
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

        q.push({0,{0,0}});

        int row[8] = {-1 , 0 , 1 , 0 , -1 , 1 , -1 , 1};
        int col[8] = {0, -1 , 0 , 1 , -1 , 1 , 1 , -1};

        dist[0][0] = 0;
        while(!q.empty()){
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r == m-1 && c == n-1) return dis+1;
            for(int i = 0 ; i < 8 ; i++){
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && 
                   nc >= 0 && nc < n &&
                   grid[nr][nc] == 0 && dis+1 < dist[nr][nc])
                   {
                    dist[nr][nc] = dis + 1;
                    q.push({dis+1 , {nr,nc}});
                   }
            }
        }
        return -1;
    }
};