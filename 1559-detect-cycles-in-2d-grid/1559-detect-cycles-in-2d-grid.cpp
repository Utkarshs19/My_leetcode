class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid) {
        vis[i][j] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            if (grid[ni][nj] != grid[i][j])
                continue;

            if (vis[ni][nj] == 1 && !(ni == pi && nj == pj))
                return true;

            if (vis[ni][nj] == -1) {
                if (dfs(ni, nj, i, j, grid))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == -1) {
                    if (dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }
        return false;
    }
};
