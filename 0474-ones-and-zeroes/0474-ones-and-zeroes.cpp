class Solution {
public:

    int helper(int i,int m,int n,vector<pair<int,int>> &v,vector<vector<vector<int>>> &dp)
    {
        if(i==v.size())
        {
            return 0;
        }

        if(dp[i][m][n]!=-1)return dp[i][m][n];

        int take=0;

        if(v[i].first<=m && v[i].second<=n)
        {
            take=1+helper(i+1,m-v[i].first,n-v[i].second,v,dp);
        }
        int notTake=helper(i+1,m,n,v,dp);

        return dp[i][m][n]=max(take,notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int,int>> v;

        for(auto i:strs)
        {
            int ones=count(i.begin(),i.end(),'1');
            int zeros=i.size()-ones;

            v.push_back({zeros,ones});
        }

vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));


    return helper(0,m,n,v,dp);

        
    }
};