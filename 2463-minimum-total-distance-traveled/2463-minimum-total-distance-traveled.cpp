class Solution {
public:
    int n,m;
    vector<vector<long long>> dp;

    long long helper(int i,int j,vector<int> &robot,vector<vector<int>> &factory)
    {
        if(i==n)return 0;
        if(j==m)return 1e15;
        if(dp[i][j]!=-1)return dp[i][j];

        long long ans=helper(i,j+1,robot,factory);

        long long cost=0;
        int pos=factory[j][0];
        int limit=factory[j][1];

        for(int k=0;k<limit && (i+k)<n; k++)
        {
            cost+=abs(robot[i+k]-pos);
            ans=min(ans,cost+helper(i+k+1,j+1,robot,factory));
        }

        return dp[i][j]=ans;
    }


    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        n=robot.size();
        m=factory.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        dp.resize(n+1,vector<long long>(m+1,-1));

        return helper(0,0,robot,factory);
        
    }
};