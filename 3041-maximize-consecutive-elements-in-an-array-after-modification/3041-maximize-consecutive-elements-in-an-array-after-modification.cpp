class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int val,vector<int> &nums)
    {
        
        int j=lower_bound(begin(nums)+i,end(nums),val)-begin(nums);

        if(j<nums.size() && nums[j]==val)return j;
        return -1;

    }
    int helper(int i,int inc,vector<int>& nums)
    {
        if(dp[i][inc]!=-1)return dp[i][inc];
        int cur_val=nums[i]+inc;
        int len=1;

        int j=-1;
        j=solve(i+1,cur_val+1,nums);
        if(j!=-1)
        {
            len=max(len,1+helper(j,0,nums));
        }
        j=-1;
        j=solve(i+1,cur_val,nums);
        if(j!=-1)
        {
            len=max(len,1+helper(j,1,nums));
        }

        return dp[i][inc]= len;
    }
    int maxSelectedElements(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        dp.resize(nums.size()+1,vector<int>(3,-1));
        
        int ans=1;

        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,helper(i,0,nums));
            ans=max(ans,helper(i,1,nums));
        }

        return ans;
    }
};