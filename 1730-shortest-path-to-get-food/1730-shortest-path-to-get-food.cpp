class Solution {
public:
    int getFood(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int step=0;

        int x,y;
        set<pair<int,int>> st;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='*')
                {
                    x=i;
                    y=j;
                }

                if(grid[i][j]=='#')
                {
                    st.insert({i,j});
                }
            }
        }

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int a=q.front().first;
                int b=q.front().second;
                q.pop();

                if(st.count({a,b}))return step;

                if(a-1>=0 && !vis[a-1][b] && grid[a-1][b]!='X')
                {
                    vis[a-1][b]=1;
                    q.push({a-1,b});
                }

                if(a+1<n && !vis[a+1][b] && grid[a+1][b]!='X')
                {
                    vis[a+1][b]=1;
                    q.push({a+1,b});
                }

                if(b-1>=0 && !vis[a][b-1] && grid[a][b-1]!='X')
                {
                    vis[a][b-1]=1;
                    q.push({a,b-1});
                }

                if(b+1<m && !vis[a][b+1] && grid[a][b+1]!='X')
                {
                    vis[a][b+1]=1;
                    q.push({a,b+1});
                }
            }
            step++;
        }
        
        return -1;
    }
};