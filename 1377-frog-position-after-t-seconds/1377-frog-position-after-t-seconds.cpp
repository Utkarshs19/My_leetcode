class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int,double>> q;
        q.push({1,1.0});
        vector<int> vis(n+1,0);
        vis[1]=1;
        int time=0;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                int node=q.front().first;
                double val=q.front().second;
                q.pop();


                if(time==t)
                {
                    if(node==target)return val;
                    continue;
                }

                int cnt=0;
                for(auto i:adj[node])
                {
                    if(!vis[i])cnt++;
                }

                if(cnt==0)
                {
                    q.push({node,val});
                    continue;
                }

                for(auto i:adj[node])
                {
                    if(!vis[i])
                    {
                        vis[i]=1;
                        q.push({i,((1.0*val)/cnt)});
                    }
                }
            }
            time++;
        }

        return 0.0;

    }
};