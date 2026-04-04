class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;
        q.push({{start[0],start[1]},0});
        vis[start[0]][start[1]]=1;

        vector<vector<int>> v;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                int x=q.front().first.first;
                int y=q.front().first.second;
                int cost=q.front().second;

                q.pop();

                if(grid[x][y]>=pricing[0] && grid[x][y]<=pricing[1])
                {
                    v.push_back({cost,grid[x][y],x,y});
                }

                if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]!=0)
                {
                    vis[x-1][y]=1;
                    q.push({{x-1,y},cost+1});
                }

                if(x+1<n && !vis[x+1][y] && grid[x+1][y]!=0)
                {
                    vis[x+1][y]=1;
                    q.push({{x+1,y},cost+1});
                }

                if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]!=0)
                {
                    vis[x][y-1]=1;
                    q.push({{x,y-1},cost+1});
                }

                if(y+1<m && !vis[x][y+1] && grid[x][y+1]!=0)
                {
                    vis[x][y+1]=1;
                    q.push({{x,y+1},cost+1});
                }
            }   
        }

        vector<vector<int>> ans;
        sort(v.begin(),v.end());

        for(int i=0;i<min((int)v.size(),k);i++)
        {
            ans.push_back({v[i][2],v[i][3]});
        }
       
        return ans;

    }
};