class Solution {
public:
    int dp[301][11];
    int n;
    vector<int> M;
    int helper(int i,vector<int> &jobDifficulty,int d)
    {
        if(d==1)
        {
            return M[i];
        }
        if(dp[i][d]!=-1)return dp[i][d];

        int res=INT_MAX;
        int maxi=jobDifficulty[i];
        for(int j=i;j<=n-d;j++)
        {
            maxi=max(maxi,jobDifficulty[j]);

            int result=maxi+helper(j+1,jobDifficulty,d-1);

            res=min(res,result);
        }

        return dp[i][d]= res;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->n=jobDifficulty.size();
        M.resize(n);
        M[n-1]=jobDifficulty[n-1];
        for(int i=n-2;i>=0;i--)
        {
            M[i]=max(M[i+1],jobDifficulty[i]);
        }
        if(n<d)return -1;
        memset(dp,-1,sizeof(dp));
        return helper(0,jobDifficulty,d);
    }
};