class Solution {
public:
    vector<pair<int,int>> v;
    int n,m;
    void dfs(int i,int j,vector<vector<int>> &land,vector<vector<int>> &vis)
        {
            vis[i][j]=1;
            v.push_back({i,j});

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
                    v.clear();
                    dfs(i,j,land,vis);
                    if(v.size()>0)
                    {
                        sort(v.begin(),v.end());
                        auto[x,y]=v[0];
                        auto[a,b]=v[v.size()-1];

                        ans.push_back({x,y,a,b});
                    }
                }
            }
        }

        return ans;
        
        
    }
};