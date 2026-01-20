class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int ans=0;

        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)q.push({i,j});
            }
        }

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                if(x-1>=0 && grid[x-1][y]==0)
                {
                    q.push({x-1,y});
                    grid[x-1][y]=-1;
                }

                if(x+1<n && grid[x+1][y]==0)
                {
                    q.push({x+1,y});
                    grid[x+1][y]=-1;
                }

                if(y-1>=0 && grid[x][y-1]==0)
                {
                    q.push({x,y-1});
                    grid[x][y-1]=-1;
                }

                if(y+1<m && grid[x][y+1]==0)
                {
                    q.push({x,y+1});
                    grid[x][y+1]=-1;
                }
            }
            ans++;
        }
        
        return ans-1==0?-1:ans-1;

    }
};