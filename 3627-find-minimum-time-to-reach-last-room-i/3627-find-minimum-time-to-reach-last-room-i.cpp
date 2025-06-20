
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<> 
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        while (!pq.empty()) {
            auto [t, pos] = pq.top();
            pq.pop();
            auto [r, c] = pos;
            
            if (t > dist[r][c]) continue;
            
            if (r == m - 1 && c == n - 1)
                return t;

            for (auto &d: dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                    
                int wait = max(moveTime[nr][nc], t);
                int nt = wait + 1;
                if (nt < dist[nr][nc]) {
                    dist[nr][nc] = nt;
                    pq.push({nt, {nr, nc}});
                }
            }
        }
        
        return -1;
    }
};
