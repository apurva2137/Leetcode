class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<
                pair<int, pair<int, int>>,              
                vector<pair<int, pair<int, int>>>,      
                greater<pair<int, pair<int, int>>>     
            > pq;

        vector<vector<int>> dis(m , vector<int>(n,INT_MAX));

        pq.push({0,{0,0}});
        
        int row[4] = {-1 , 0 , 1 , 0};
        int col[4] = {0 , -1 , 0 , 1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == m-1 && c == n-1) return diff;

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >=0 && nr < m && nc >= 0 && nc < n ){
                    int effort = abs(heights[nr][nc] - heights[r][c]);
                    int newdiff = max(effort, diff);
                    if(newdiff < dis[nr][nc]){
                        dis[nr][nc] = newdiff;
                        pq.push({newdiff,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};