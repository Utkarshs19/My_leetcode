class Solution {
public:
    
    int cnt=0;

    long long dfs(int node,int par,vector<vector<int>> &adj,vector<int>&values,int k)
    {
        long long sum=values[node];


        for(auto cur:adj[node])
        {
            if(cur==par)continue;
            sum+=dfs(cur,node,adj,values,k);
        }

        if(sum==k)
        {
            cnt++;
            return 0;
        }

        return sum;

    }


    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        
        int ans=0;
        if(edges.size()==0)return 0;

        vector<vector<int>> adj(nums.size());

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        set<int> st;

        long long S = 0;
        for (int x : nums) S += x;

        for (long long d = 1; d * d <= S; d++) {

            
            if (S % d == 0) {

                cnt = 0;
                dfs(0, -1, adj, nums, d);

                if (cnt == S / d) {
                    ans = max(ans, (int)cnt - 1);
                }

                if (d != S / d) {
                    long long t = S / d;
                    cnt = 0;
                    dfs(0, -1, adj, nums, t);

                    if (cnt == S / t) {
                        ans = max(ans, (int)cnt - 1);
                    }
                }

            }
        }

        return ans;
       
    }
};
