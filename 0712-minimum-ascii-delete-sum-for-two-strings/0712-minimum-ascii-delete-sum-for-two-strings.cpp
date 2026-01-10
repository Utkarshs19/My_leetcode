class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i,int j,string &s1,string &s2)
    {
        if(i>=s1.length())
        {
            int sum=0;
            for(int k=j;k<s2.length();k++)
            sum+=(int)s2[k];

            return sum;
        }

        if(j>=s2.length())
        {
            int sum=0;
            for(int k=i;k<s1.length();k++)sum+=(int)s1[k];

            return sum;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i]==s2[j])
        return dp[i][j]=helper(i+1,j+1,s1,s2);
        else
    return dp[i][j]=min((int)s1[i]+helper(i+1,j,s1,s2) , (int)s2[j]+helper(i,j+1,s1,s2));

    }
    int minimumDeleteSum(string s1, string s2) {

        dp.assign(s1.length()+1,(vector<int>(s2.length()+1,-1)));

        return helper(0,0,s1,s2);
        
    }
};