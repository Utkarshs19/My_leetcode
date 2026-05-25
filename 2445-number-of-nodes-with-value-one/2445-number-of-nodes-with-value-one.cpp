class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {

        vector<int> v(n+1,0);

        for(int i=0;i<queries.size();i++)
        {
            v[queries[i]]++;
        }

        for(int i=1;i<=n;i++)
        {
            v[i]+=(v[i/2]);
        }

        int ans=0;

        for(int i=1;i<=n;i++)
        {
            if(v[i]%2==1)ans++;
        }
        return ans;
        
    }
};