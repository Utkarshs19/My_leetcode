class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        int vis[51][51][201];
        memset(vis, 0, sizeof(vis));

        health -= grid[0][0];
        if (health <= 0) return false;

        queue<tuple<int,int,int>> q;
        q.push({0, 0, health});
        vis[0][0][health] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y, h] = q.front();
            q.pop();

            if (x == n-1 && y == m-1) return true;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int nh = h - grid[nx][ny];  
                if (nh <= 0) continue;      
                if (vis[nx][ny][nh]) continue;

                vis[nx][ny][nh] = 1;
                q.push({nx, ny, nh});
            }
        }
        return false;
    }
};