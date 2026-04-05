class Solution {
public:
    int n,m;
    vector<vector<int>> dist;

    bool helper(int mid,vector<vector<int>> &grid)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                if(dist[x][y]<mid)continue;

                if(x==n-1 && y==m-1)return true;

                if(x-1>=0 && !vis[x-1][y])
                {
                    vis[x-1][y]=1;
                    q.push({x-1,y});
                }

                if(x+1<n && !vis[x+1][y])
                {
                    vis[x+1][y]=1;
                    q.push({x+1,y});
                }

                if(y-1>=0 && !vis[x][y-1])
                {
                    vis[x][y-1]=1;
                    q.push({x,y-1});
                }

                if(y+1<m && !vis[x][y+1])
                {
                    vis[x][y+1]=1;
                    q.push({x,y+1});
                }
            }
        }

        return false;


    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();

        dist.resize(n,vector<int>(m));

        queue<pair<int,int>> q;
        int step=0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        int low=0;
        int high=0;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                dist[x][y]=step;
                high=max(high,step);
                q.pop();

                if(x-1>=0 && !vis[x-1][y])
                {
                    vis[x-1][y]=1;
                    q.push({x-1,y});
                }

                if(x+1<n && !vis[x+1][y])
                {
                    vis[x+1][y]=1;
                    q.push({x+1,y});
                }

                if(y-1>=0 && !vis[x][y-1])
                {
                    vis[x][y-1]=1;
                    q.push({x,y-1});
                }

                if(y+1<m && !vis[x][y+1])
                {
                    vis[x][y+1]=1;
                    q.push({x,y+1});
                }
            }
            step++;
        }

        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(helper(mid,grid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }

        return ans;

    }
};