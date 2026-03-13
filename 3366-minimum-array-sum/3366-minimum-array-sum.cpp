class Solution {
public:
   
    long long dp[101][101][101];

    long long helper(int i,vector<int> &nums,int k,int op1,int op2)
    {
        if(i==nums.size())
        {
            return 0;
        }


        if(dp[i][op1][op2]!=-1)
        return dp[i][op1][op2];

        long long res=nums[i]+helper(i+1,nums,k,op1,op2);

        if(op1>0)
        {
            res=min(res,(long long)((nums[i]+1)/2)+helper(i+1,nums,k,op1-1,op2));
        }

        if(op2>0)
        {
            if(nums[i]>=k)
            res=min(res,(long long)(nums[i]-k)+helper(i+1,nums,k,op1,op2-1));
        }

        if(op1>0 && op2>0)
        {
            long long temp=(nums[i]+1)/2;
            if(temp>=k)
            {
                res=min(res,(temp-k+helper(i+1,nums,k,op1-1,op2-1)));
            }

            temp=nums[i];
            if(temp>=k)
            {
                temp=temp-k;

                res=min(res,((temp+1)/2+helper(i+1,nums,k,op1-1,op2-1)));
            }

        }

        return dp[i][op1][op2]=res;

    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        
        memset(dp,-1,sizeof(dp));

        return helper(0,nums,k,op1,op2);

    }
};