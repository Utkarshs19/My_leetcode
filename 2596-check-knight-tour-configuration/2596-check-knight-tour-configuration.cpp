class Solution {
public:
     map<pair<int,int>,int>m;
     int n;
    void dfs(int i,int j,vector<vector<int>> &vis,int k)
    {
        if(m[{i,j}]==k)
        {
            vis[i][j]=1;
            k++;
            if(i+1<n && j+2<n && vis[i+1][j+2]==-1)
            dfs(i+1,j+2,vis,k);
            
            if(i-1>=0 && j+2<n && vis[i-1][j+2]==-1)
            dfs(i-1,j+2,vis,k);

            if(i+1<n && j-2>=0 && vis[i+1][j-2]==-1)
            dfs(i+1,j-2,vis,k);

            if(i-1>=0 && j-2>=0 && vis[i-1][j-2]==-1)
            dfs(i-1,j-2,vis,k);

            if(i+2<n && j+1<n && vis[i+2][j+1]==-1)
            dfs(i+2,j+1,vis,k);

            if(i+2<n && j-1>=0 && vis[i+2][j-1]==-1)
            dfs(i+2,j-1,vis,k);

            if(i-2>=0 && j+1<n && vis[i-2][j+1]==-1)
            dfs(i-2,j+1,vis,k);

            if(i-2>=0 && j-1>=0 && vis[i-2][j-1]==-1)
            dfs(i-2,j-1,vis,k);
        }
    }

    bool checkValidGrid(vector<vector<int>>& grid) {

        n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                m[{i,j}]=grid[i][j];
            }
        }


         dfs(0,0,vis,0);

         for(int i=0;i<n;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==-1)return false;
            }
            cout<<endl;
         }

         return true;
        
    }
};