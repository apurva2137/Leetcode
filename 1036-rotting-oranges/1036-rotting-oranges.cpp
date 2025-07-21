class Solution {
public:
    int orangesRotting(vector<vector<int>>& oranges) {

        queue<pair<pair<int,int>,int>> q;
        int m = oranges.size();
        int n = oranges[0].size();
        int fresh = 0;

        for(int i = 0 ; i < m ; i++){
           for(int j = 0 ; j < n ; j++){
              if(oranges[i][j] == 2) q.push({{i,j},0});
              else if(oranges[i][j] == 1) fresh++;
          }
        }
        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};
        int time = 0 ;
        int count = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time , t);
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + row[i];
                int nc = c + col[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n
                   && oranges[nr][nc] == 1){
                      oranges[nr][nc] = 2;
                      q.push({{nr,nc},t+1});
                      count++;
                }
            }
        }
        return (count == fresh) ? time : -1;
    }
};