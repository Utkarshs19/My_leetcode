class Solution {
public:

    int n,m1;
    int id=2;
    map<int,int> m;
    int cnt=0;

    bool check(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m1;
    }

    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        grid[i][j]=id;
        cnt++;

        if(check(i-1,j) && grid[i-1][j]==1 )
        dfs(i-1,j,grid);

        if(check(i+1,j) && grid[i+1][j]==1)
        dfs(i+1,j,grid);

        if(check(i,j-1) && grid[i][j-1]==1 )
        dfs(i,j-1,grid);

        if(check(i,j+1) && grid[i][j+1]==1)
        dfs(i,j+1,grid);

    }

    int largestIsland(vector<vector<int>>& grid) {

        n=grid.size();
        m1=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt=0;
                    dfs(i,j,grid);
                    m[id]=cnt;
                    id++;
                }
                  
            }
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                if(grid[i][j]==0)
                {
                    int x=0;
                    set<int> st;
                    if(check(i-1,j) && !st.count(grid[i-1][j]))
                    {
                        st.insert(grid[i-1][j]);
                        x+=m[grid[i-1][j]];
                    }
                    if(check(i+1,j) && !st.count(grid[i+1][j]))
                    {
                        st.insert(grid[i+1][j]);
                       x+=m[grid[i+1][j]];
                    }
                    if(check(i,j-1) && !st.count(grid[i][j-1]))
                    {
                        st.insert(grid[i][j-1]);
                        x+=m[grid[i][j-1]];
                    }
                    if(check(i,j+1) && !st.count(grid[i][j+1]))
                    {
                        st.insert(grid[i][j+1]);
                       x+=m[grid[i][j+1]];
                    }
                    x++;
                    ans=max(ans,x);
                }
            }
        }

        return ans==0?n*m1:ans;
    }
};