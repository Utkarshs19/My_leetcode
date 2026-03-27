class Solution {
public:

    int cost(int i,int j)
    {
        return abs(i/6-j/6)+
                abs(i%6-j%6);
    }
    int dp[27][27][301];

    int helper(int i,int j,int k,string &word)
    {
        if(k==word.length())
        {
            return 0;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];

        int target=word[k]-'A';

        int cost1=(i==26)?0:(i==target)?0:cost(target,i);
        int cost2=(j==26)?0:(j==target)?0:cost(target,j);

        int move1=cost1+helper(target,j,k+1,word);
        int move2=cost2+helper(i,target,k+1,word);

        return dp[i][j][k]=min(move1,move2);

    }


    int minimumDistance(string word) {
        
        int ans=INT_MAX;

        memset(dp,-1,sizeof(dp));
        
        return helper(26,26,0,word);
    }
};