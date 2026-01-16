class Solution {
public:
    int edgeScore(vector<int>& edges) {

        int ans;
        long long  maxi=0;

        map<int,long long > m;

        for(int i=0;i<edges.size();i++)
        {
            m[edges[i]]+=i;
            if(m[edges[i]]>maxi)
            {
                maxi=m[edges[i]];
                ans=edges[i];
            }
            else if(m[edges[i]]==maxi)
            {
                ans=min(ans,edges[i]);
            }
        }
        
        return ans;
    }
};