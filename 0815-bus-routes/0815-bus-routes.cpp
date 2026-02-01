class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source==target)return 0;
        int ans=1;

        unordered_map<int,vector<int>> m;

        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                m[routes[i][j]].push_back(i);
            }
        }

        queue<int> q;
        int n=routes.size();
        vector<int> vis(n,0);
        for(auto i:m[source])
        {
            q.push(i);
            vis[i]=1;
        }

        while(!q.empty())
        {
            int size=q.size();
            for(int x=0;x<size;x++)
            {
                int i=q.front();q.pop();

                for(auto j:routes[i])
                {
                    if(j==target)return ans;

                    for(auto k:m[j])
                    {
                        if(!vis[k])
                        {
                            vis[k]=1;
                            q.push(k);
                        }
                    }
                }

            }
            ans++;
        }        
        return -1;
    }
};