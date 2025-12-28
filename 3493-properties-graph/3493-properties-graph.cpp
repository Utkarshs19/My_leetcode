class Solution {
public:
    int x;
    bool intersect(vector<int> v1,vector<int> v2)
    {int freq[101] = {0};

    for (int x : v1) freq[x]++;

    int cnt = 0;
    for (int x : v2) {
        if (freq[x] > 0) {
            cnt++;
            freq[x] = 0;   
            if (cnt >= this->x) return true;
        }
    }
    return false;
    }

    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            {
                dfs(i,adj,vis);
            }
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {

        x=k;

        int n=properties.size();

        vector<vector<int>> adj(n);
    
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(intersect(properties[i],properties[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans=0;

        vector<int> vis(n,-1);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                ans++;

                dfs(i,adj,vis);

            }
        }
        return ans;
    }
};