class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {

        int n=maze.size();
        int m=maze[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        vis[start[0]][start[1]]=1;

        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            if(x==destination[0] && y==destination[1])return true;
            
            int i=x;
            while(i-1>=0 && maze[i-1][y]==0)
            {
                i--;
            }
            if(!vis[i][y]){
            vis[i][y]=1;
            q.push({i,y});}

            i=x;
            while(i+1<n && maze[i+1][y]==0)
            {
                i++;
            }
            if(!vis[i][y])
            {
                vis[i][y]=1;
                q.push({i,y});
            }

            int j=y;
            while(j-1>=0 &&  maze[x][j-1]==0)
            {
                j--;
            }
            if(!vis[x][j]){
                vis[x][j]=1;
            q.push({x,j});
            }

            j=y;
            while(j+1<m && maze[x][j+1]==0)
            {
                j++;
            }
            if(!vis[x][j])
            {
                vis[x][j]=1;
                q.push({x,j});
            }

        }
        
        return false;
    }
};