class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       priority_queue<
                pair<int, pair<int, int>>,              
                vector<pair<int, pair<int, int>>>,      
                greater<pair<int, pair<int, int>>>     
            > pq;

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dis(m , vector<int>(n,INT_MAX));

        pq.push({0,{0,0}});
        dis[0][0] = 0;
        
        int row[4] ={-1,1,0,0};

        int col[4] ={0,0,-1,1};

        while(!pq.empty()){

            int diff = pq.top().first;

            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            if(r == m-1 && c == n-1) return diff;

            for(int i = 0 ; i < 4; i++){
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                   int absdiff = abs(heights[nr][nc] - heights[r][c]);
                   int maxdiff = max(diff , absdiff);

                   if(maxdiff < dis[nr][nc]){
                      dis[nr][nc] = maxdiff;
                      pq.push({maxdiff , {nr,nc}});
                   }
                }
            } 
        }
        return -1;
    }
};