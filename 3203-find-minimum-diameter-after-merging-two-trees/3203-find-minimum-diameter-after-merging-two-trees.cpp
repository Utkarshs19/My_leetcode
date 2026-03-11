class Solution {
public:

    int dfs(int node,int par,vector<vector<int>> &adj,int &diameter)
    {
        int max1=0,max2=0;
        
        for(auto i:adj[node])
        {
            if(i==par)continue;

            int ht=dfs(i,node,adj,diameter)+1;

            if(ht>max1)
            {
                max2=max1;
                max1=ht;
            }
            else
            {
                max2=max(max2,ht);
            }
        }

        diameter=max(diameter,max1+max2);

        return max1;
    }

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1=edges1.size();
        n1+=1;

        int n2=edges2.size();
        n2+=1;

        vector<vector<int>> adj1(n1);
        vector<vector<int>> adj2(n2);

        for(int i=0;i<edges1.size();i++)
        {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }

         for(int i=0;i<edges2.size();i++)
        {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int d1=0,d2=0;
        dfs(0,-1,adj1,d1);
        dfs(0,-1,adj2,d2);

        return max({d1,d2,((d1+1)/2+(d2+1)/2+1)});
        

        
    }
};