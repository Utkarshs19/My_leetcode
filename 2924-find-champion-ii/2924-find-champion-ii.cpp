class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int> indegree(n,0);
        int cnt=0;
        int ans;

        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;
        }

        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0){
                ans=i;
                cnt++;
            }
        }

        return cnt==1?ans:-1;
        
    }
};