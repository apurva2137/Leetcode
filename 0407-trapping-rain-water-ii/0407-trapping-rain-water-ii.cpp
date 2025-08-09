class Solution {
public:
    int m, n;

    int d[5] = {0, 1, 0, -1, 0};

    bool isvalid(int x, int y) { 
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int trapRainWater(vector<vector<int>>& h) {
        m = h.size();
        n = h[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pq.push({h[i][0], i, 0});
            pq.push({h[i][n - 1], i, n - 1});
            vis[i][0] = vis[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({h[0][j], 0, j});
            pq.push({h[m - 1][j], m - 1, j});
            vis[0][j] = vis[m - 1][j] = true;
        }

        int res = 0;

        while (!pq.empty()) {
            int ch=pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int x = i + d[k];
                int y = j + d[k + 1];

                if (!isvalid(x, y) || vis[x][y])
                    continue;
                if (h[x][y] < ch)
                    res += ch - h[x][y];

                vis[x][y] = true;
                
                pq.push({max(ch, h[x][y]), x, y});
            }
        }
        return res;
    }
};