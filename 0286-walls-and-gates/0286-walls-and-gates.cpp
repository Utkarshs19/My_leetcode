class Solution {
public:

    const int inf=2147483647;

    void wallsAndGates(vector<vector<int>>& rooms) {

        queue<pair<pair<int,int>,int>> q;

        int n=rooms.size();
        int m=rooms[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(rooms[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=1;
                }
            }
        }


        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                int x=q.front().first.first;
                int y=q.front().first.second;
                int dis=q.front().second;
                q.pop();
                cout<<x<<" "<<y<<" "<<dis<<endl;
                rooms[x][y]=dis;

                if(x-1>=0 && rooms[x-1][y]!=-1 && !vis[x-1][y])
                {
                    vis[x-1][y]=1;
                    q.push({{x-1,y},dis+1});
                }

                if(x+1<n && rooms[x+1][y]!=-1 && !vis[x+1][y])
                {
                    vis[x+1][y]=1;
                    q.push({{x+1,y},dis+1});
                }

                if(y-1>=0 && rooms[x][y-1]!=-1 && !vis[x][y-1])
                {
                    vis[x][y-1]=1;
                    q.push({{x,y-1},dis+1});
                }

                if(y+1<m && rooms[x][y+1]!=-1 && !vis[x][y+1])
                {
                    vis[x][y+1]=1;
                    q.push({{x,y+1},dis+1});
                }

            }

        }
        
    }
};