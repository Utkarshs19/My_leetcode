class Solution {
public:
    int longestBalanced(string s) {

        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            map<int,int> m;
            int k=0;

            for(int j=i;j<s.length();j++)
            {
                m[s[j]]++;
                k=max(k,m[s[j]]);

                bool flag=true;

                for(auto i:m)
                {
                    if(i.second!=k)
                    {
                        flag=false;
                        break;
                    }
                }


                if(flag==true)
                {
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};