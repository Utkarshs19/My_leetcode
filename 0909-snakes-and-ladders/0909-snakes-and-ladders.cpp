class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        q.push(1);

        vector<int> ans(n*n + 1, -1);
        ans[1] = 0;   

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 1; i <= 6 && x + i <= n*n; i++) {
                int y = x + i;

                int row = (y - 1) / n;
                int col = (y - 1) % n;

                int val = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                int v = (val == -1 ? y : val);

                if (v == n*n)
                    return ans[x] + 1;

                if (ans[v] == -1) {
                    ans[v] = ans[x] + 1;
                    q.push(v);
                }
            }
        }

        return -1;
    }
};