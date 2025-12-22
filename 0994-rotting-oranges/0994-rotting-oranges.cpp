class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        int cnt=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
                if(grid[i][j]==1)
                cnt++;
            }
        }
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        while(!q.empty())
        {
            int size=q.size();

            if(cnt==0)break;
            ans++;
            
            for(int i=0;i<size;i++)
            {
            
            int x=q.front().first;
            int y=q.front().second;

            grid[x][y]=3;

            q.pop();

            if(x-1>=0 && grid[x-1][y]==1)
            {
                q.push({x-1,y});
                cnt--;
                grid[x-1][y]=2;
            }

            if(x+1<n && grid[x+1][y]==1)
            {
                q.push({x+1,y});
                cnt--;
                grid[x+1][y]=2;
            }

            if(y-1>=0 && grid[x][y-1]==1)
            {
                q.push({x,y-1});
                cnt--;
                grid[x][y-1]=2;
            }

            if(y+1<m && grid[x][y+1]==1)
            {
                q.push({x,y+1});
                cnt--;
                grid[x][y+1]=2;
            }
            }

        }

        if(cnt>0)return -1;

        return ans;
        
    }
};