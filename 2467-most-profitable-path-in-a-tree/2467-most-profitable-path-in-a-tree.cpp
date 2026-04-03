class Solution {
public:
    map<int,int> m;
    int ans=INT_MIN;
    vector<int> amount;
    vector<int> vis;
   bool dfs(int node, int parent, int time, vector<vector<int>>& adj) {
    m[node] = time;
    
    if (node == 0) return true;  
    
    for (auto i : adj[node]) {
        if (i != parent) {  
            if (dfs(i, node, time + 1, adj))
                return true;  
        }
    }
    
    m.erase(node);  
    return false;
}
    void helper(int node,vector<vector<int>> &adj,int time,int sum)
    {
        vis[node]=1;
        if(!m.count(node))
        sum+=amount[node];
        else
        {
            if(time<m[node])
                sum+=amount[node];
            else if(time==m[node])
            {
                sum+=amount[node]/2;
            }
        }
        bool leaf=true;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {   
                leaf=false;
                helper(i,adj,time+1,sum);
            }
        }

        if(leaf)
        ans=max(ans,sum); 

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        int n=edges.size()+1;

        vector<vector<int>> adj(n);
        this->amount=amount;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(bob,-1,0,adj);
        vis.resize(n,0);
        helper(0,adj,0,0);
       
       return ans; 
        
    }
};