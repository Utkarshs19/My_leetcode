class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {

        const long long inf=1e18;

        vector<long long > v(n,inf);

        v[0]=0;

        for(int i=0;i<restrictions.size();i++)
        {
            v[restrictions[i][0]]=restrictions[i][1];
        }

        for(int i=0;i<n-1;i++)
        {
            v[i+1]=min(v[i+1],v[i]+diff[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            v[i]=min(v[i],v[i+1]+diff[i]);
        }

        return *max_element(v.begin(),v.end());
        
    }
};