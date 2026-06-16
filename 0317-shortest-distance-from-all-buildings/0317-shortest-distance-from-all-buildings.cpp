class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        vector<vector<int>> v1(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                    queue<pair<int,int>> q;
                    vector<vector<int>> vis(n,vector<int>(m,0));
                    q.push({i,j});
                    vis[i][j]=1;
                    int step=0;
                    while(!q.empty())
                    {
                        int size=q.size();
                        for(int k=0;k<size;k++)
                        {
                            int x=q.front().first;
                            int y=q.front().second;
                            q.pop();

                            if(grid[x][y]==0){
                            if(v[x][y]==INT_MAX)
                                v[x][y]=0;
                                v[x][y]+=step;
                                v1[x][y]++;
                            }
                            if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]==0)
                            {
                                vis[x-1][y]=1;
                                q.push({x-1,y});
                            }
                            if(x+1<n && !vis[x+1][y] && grid[x+1][y]==0)
                            {
                                vis[x+1][y]=1;
                                q.push({x+1,y});
                            }
                            if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]==0)
                            {
                                vis[x][y-1]=1;
                                q.push({x,y-1});
                            }
                            if(y+1<m && !vis[x][y+1] && grid[x][y+1]==0)
                            {
                                vis[x][y+1]=1;
                                q.push({x,y+1});
                            }
                        }
                        step++;
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && v[i][j]!=INT_MAX && v1[i][j]==cnt)
                {
                    ans=min(ans,v[i][j]);
                }
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};