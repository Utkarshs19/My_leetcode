class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<vector<int>> q;
        for(int i=0;i<sources.size();i++)
        {
            q.push(sources[i]);
            vis[sources[i][0]][sources[i][1]]=sources[i][2];
        }


        while(!q.empty())
        {
            int size=q.size();
            set<vector<int>> st;
            set<pair<int,int>> p;
            st.clear();
            p.clear();
            for(int i=0;i<size;i++)
            {
                int x=q.front()[0];
                int y=q.front()[1];
                int col=q.front()[2];
                q.pop();

                if(x-1>=0 && !vis[x-1][y])
                {
                    st.insert({x-1,y,col});
                    p.insert({x-1,y});
                }

                if(y-1>=0 && !vis[x][y-1])
                {
                    st.insert({x,y-1,col});
                    p.insert({x,y-1});
                }

                if(x+1<n && !vis[x+1][y])
                {
                    st.insert({x+1,y,col});
                    p.insert({x+1,y});
                }

                if(y+1<m && !vis[x][y+1])
                {
                    st.insert({x,y+1,col});
                    p.insert({x,y+1});
                }
            }

            for(auto i:st)
            {
                vector<int> v=i;
                vis[v[0]][v[1]]=max(vis[v[0]][v[1]],v[2]);
            }

            for(auto i:p)
            {
                q.push({i.first,i.second,vis[i.first][i.second]});
            }       
        }

        return vis;

        
    }
};