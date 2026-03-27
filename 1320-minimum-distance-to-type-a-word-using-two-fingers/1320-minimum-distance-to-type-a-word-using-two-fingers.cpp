class Solution {
public:

    int cost(int i,int j)
    {
        return abs(m['A'+i].first-m['A'+j].first)+
                abs(m['A'+i].second-m['A'+j].second);
    }

    map<char,pair<int,int>> m;

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

        m['A']={0,0};
        m['B']={0,1};
        m['C']={0,2};
        m['D']={0,3};
        m['E']={0,4};
        m['F']={0,5};
        m['G']={1,0};
        m['H']={1,1};
        m['I']={1,2};
        m['J']={1,3};
        m['K']={1,4};
        m['L']={1,5};
        m['M']={2,0};
        m['N']={2,1};
        m['O']={2,2};
        m['P']={2,3};
        m['Q']={2,4};
        m['R']={2,5};
        m['S']={3,0};
        m['T']={3,1};
        m['U']={3,2};
        m['V']={3,3};
        m['W']={3,4};
        m['X']={3,5};
        m['Y']={4,0};
        m['Z']={4,1};


        int ans=INT_MAX;

        memset(dp,-1,sizeof(dp));
        
        return helper(26,26,0,word);
    }
};