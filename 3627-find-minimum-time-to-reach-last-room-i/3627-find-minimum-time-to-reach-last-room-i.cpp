class Solution {
public:
    int minTimeToReach(vector<vector<int>>& time) {
        int m = time.size();
        int n = time[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});

        vector<vector<int>> dis(m , vector<int>(n,INT_MAX));
        dis[0][0] = 0;
        int row[4] = {-1 , 0 , 1 , 0};
        int col[4] = {0 , -1 , 0 , 1};

        while(!pq.empty()){
             auto [t, pos] = pq.top(); 
             int r = pos.first, c = pos.second;
             pq.pop();
             
             if (t > dis[r][c]) continue;
            
             if(r == m-1 && c == n-1) return t;

             for(int i = 0 ; i < 4 ; i++){

                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc>=0 && nc < n){
                    int waittime = max(t , time[nr][nc]);
                    int wt = waittime + 1;
                    if(wt < dis[nr][nc]){
                    dis[nr][nc] = wt;
                    pq.push({wt, {nr,nc}});
                    }
                }
             }
        }
        return -1;
    }
};