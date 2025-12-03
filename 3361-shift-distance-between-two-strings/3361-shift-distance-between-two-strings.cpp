class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& prevCost) {

        vector<vector<long long>> v(26,vector<long long>(26,INT_MAX));


        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(i==j)v[i][j]=0;

                long long x=0;

                if(i<j)
                {
                    for(int a=i;a<=j-1;a++)
                    {
                        x+=nextCost[a];
                    }
                }
                else
                {
                    for(int a=i;a<=25;a++)
                    {
                        x+=nextCost[a];
                    }
                    for(int a=0;a<=j-1;a++)
                    {
                        x+=nextCost[a];
                    }
                }

                long long y=0;

                if(i<j)
                {
                    for(int a=i;a>=0;a--)
                    {
                        y+=prevCost[a];
                    }
                    for(int a=25;a>=j+1;a--)
                    {
                        y+=prevCost[a];
                    }

                }
                else
                {
                    for(int a=i;a>=j+1;a--)
                    {
                        y+=prevCost[a];
                    }
                }


                v[i][j]=min(x,y);


            }
        }
        long long ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==t[i])continue;
            else
            {
                ans+=v[s[i]-'a'][t[i]-'a'];
            }
        }

        return ans;
        
    }
};