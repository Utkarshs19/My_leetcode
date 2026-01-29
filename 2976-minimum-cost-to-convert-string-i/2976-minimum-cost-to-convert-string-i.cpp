class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        vector<vector<long long int>> v(26,vector<long long int>(26,INT_MAX));

        for(int i=0;i<original.size();i++)
        {   
            int x=original[i]-'a';
            int y=changed[i]-'a';

            v[x][y]=min(v[x][y],(long long int)cost[i]);
            
        }

        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    v[i][j]=min(v[i][j],(v[i][k]+v[k][j]));
                }
            }
        }

        long long ans=0;
        for(int i=0;i<source.length();i++)
        {
            if(source[i]==target[i])continue;

            if(v[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;

            ans+=v[source[i]-'a'][target[i]-'a'];
        }

        return ans;
        
    }
};