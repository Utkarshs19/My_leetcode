class Solution {
public:
    vector<pair<int,int>> v;
    int n,m;
    int x,y;
    void dfs(int i,int j,vector<vector<int>> &land,vector<vector<int>> &vis)
        {
            vis[i][j]=1;
            x=max(x,i);
            y=max(y,j);

            if(i-1>=0 && vis[i-1][j]==-1 && land[i-1][j]==1)
            {
                dfs(i-1,j,land,vis);
            }

            if(i+1<n && vis[i+1][j]==-1 && land[i+1][j]==1)
            {
                dfs(i+1,j,land,vis);
            }


            if(j-1>=0 && vis[i][j-1]==-1 && land[i][j-1]==1)
            {
                dfs(i,j-1,land,vis);
            }

            if(j+1<m && vis[i][j+1]==-1 && land[i][j+1]==1)
            {
                dfs(i,j+1,land,vis);
            }
        }


    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        n=land.size();
        m=land[0].size();

        vector<vector<int>> vis(n,vector<int>(m,-1));

        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==-1 && land[i][j]==1)
                {
                    x=i;
                    y=j;
                    dfs(i,j,land,vis);
                    ans.push_back({i,j,x,y});
                }
            }
        }

        return ans;
        
        
    }
};