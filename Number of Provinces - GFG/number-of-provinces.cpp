//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    int cnt=0;
    
    void dfs(int i,vector<int> &vis,vector<int> ADJ[])
    {
        vis[i]=1;
        
        for(auto u:ADJ[i])
        {
           if(!vis[u])
           {
               dfs(u,vis,ADJ);
           }
            
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> ADJ[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1&&i!=j)
                {
                    ADJ[i].push_back(j);
                    ADJ[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {   
            if(!vis[i])
            {
            cnt++;  
            dfs(i,vis,ADJ);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends