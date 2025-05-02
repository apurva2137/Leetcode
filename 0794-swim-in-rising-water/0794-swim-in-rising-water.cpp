class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0, r = n * n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isPossible(grid, mid)) r = mid;
            else  l = mid + 1;
        }
        return r;
    }

private:
    vector<vector<bool>> vis;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isPossible(vector<vector<int>>& grid, int mid) {
        if (grid[0][0] > mid)   return false;
        vis = vector<vector<bool>>(grid.size(), vector<bool>(grid.size(), false));
        return dfs(0, 0, mid, grid);
    }

    bool dfs(int x, int y, int mid, vector<vector<int>>& g) {
        int n = g.size();
        vis[x][y] = true;
        if (x == n - 1 && y == n - 1)   return true;

        for (int i = 0; i < 4; i++) {
            int a = x + dir[i].first, b = y + dir[i].second;
            if (a >= 0 && a < n && b >= 0 && b < n && g[a][b] <= mid && !vis[a][b])
                if (dfs(a, b, mid, g))
                    return true;
        }
        return false;
    }
};