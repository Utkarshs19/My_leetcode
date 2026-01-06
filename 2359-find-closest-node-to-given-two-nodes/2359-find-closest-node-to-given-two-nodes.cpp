class Solution {
public:
    void dfs(int node,vector<int> &edges,vector<int> &dist,vector<int>&vis)
    {
        vis[node]=1;
        int neighbor=edges[node];
        if(neighbor!=-1 && vis[neighbor]==0)
        {
            dist[neighbor]=dist[node]+1;
            dfs(neighbor,edges,dist,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int n=edges.size();

        int ans=-1;

        int mini=INT_MAX;

        vector<int> dist1(n,0),dist2(n,0);
        vector<int> vis1(n,0),vis2(n,0);

        dfs(node1,edges,dist1,vis1);
        dfs(node2,edges,dist2,vis2);

        for(int i=0;i<n;i++)
        {
            if(vis1[i] && vis2[i] && mini>max(dist1[i],dist2[i]))
            {
                mini=max(dist1[i],dist2[i]);
                ans=i;
            }
        }

        return ans;
        
    }
};