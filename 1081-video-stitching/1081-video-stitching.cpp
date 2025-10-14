class Solution {
public:

    int helper(int ind,int prev,vector<vector<int>> &clips,int time,vector<vector<int>> &dp)
    {
        if(ind==clips.size()){
            if(clips[prev][1]>=time)return 0;
            return 1e9;
        }

        if(clips[prev][1]>=time)return 0;

        if(dp[ind][prev]!=-1)return dp[ind][prev];

        int take=1e9;

        if(clips[ind][0]<=clips[prev][1])
        {
            take=1+helper(ind+1,ind,clips,time,dp);
        }
        int notTake=helper(ind+1,prev,clips,time,dp);

        return dp[ind][prev]=min(take,notTake);
    }

    int videoStitching(vector<vector<int>>& clips, int time) {

        sort(clips.begin(),clips.end());

        int n=clips.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int ans=1e9;
        for(int i=0;i<clips.size();i++)
        {
            if(clips[i][0]==0)
            {
                ans=min(ans,1+helper(i+1,i,clips,time,dp));
            }
        }
        if(ans==1e9)return -1;
        return ans;
        
    }
};