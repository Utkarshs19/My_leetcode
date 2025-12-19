// normal bfs from water
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int N=isWater.size();
        int M=isWater[0].size();

        vector<vector<int>> ans(N,vector<int>(M,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(isWater[i][j]==1)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (auto d : dir) {
                int dx = x + d.first;
                int dy = y + d.second;
                if (dx >= 0 && dx < N && dy >= 0 && dy < M && ans[dx][dy] == -1) {
                    ans[dx][dy] = ans[x][y] + 1;
                    q.push({dx, dy});
                }
            }
        }

        return ans;
        
    }
};