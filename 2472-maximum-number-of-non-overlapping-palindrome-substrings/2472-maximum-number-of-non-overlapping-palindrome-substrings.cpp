class Solution {
public:
    int n;
    int dp[2001][2001];
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(string &s,int k,int i,int j)
    {
        if(i>=n || j>=n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(isPalindrome(s,i,j))
        {
            int take=1+helper(s,k,j+1,j+k);
            int grow=helper(s,k,i,j+1);
            int slide=helper(s,k,i+1,j+1);

            return dp[i][j]= max({take,grow,slide});
        }
        else
        {
            int grow=helper(s,k,i,j+1);
            int slide=helper(s,k,i+1,j+1);

            return dp[i][j]= max({grow,slide});
        }
    }
    int maxPalindromes(string s, int k) {
        
        this->n=s.length();
        if(k==1)return n;
        memset(dp,-1,sizeof(dp));
        return helper(s,k,0,k-1);
        
    }
};