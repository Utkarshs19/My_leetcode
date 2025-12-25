class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        int m=grid[0].size();

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        vector<vector<int>> vis(n,vector<int>(m,-1));

        queue<pair<pair<int,int>,int>> q;

        q.push({{0,0},k});

        vis[0][0]=k;
        int ans=0;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                int x=q.front().first.first;
                int y=q.front().first.second;
                int rem=q.front().second;
                q.pop();

                if(x==n-1 && y==m-1)return ans;

                for(int d=0;d<4;d++)
                {
                    int nx=x+dx[d];
                    int ny=y+dy[d];

                    if(nx<0 || ny<0 || nx>=n || ny>=m)
                    continue;

                    int newK=rem-grid[nx][ny];

                    if(newK<0)continue;

                    if(vis[nx][ny]>=newK)continue;

                    vis[nx][ny]=newK;
                    q.push({{nx,ny},newK});
                }
            }

            ans++;
        }

        return -1;
        
    }
};