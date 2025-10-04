class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {

        int ans=0;

        map<char,int> m;

        for(int i=0;i<chars.length();i++)
        {
            m[chars[i]]=vals[i];
        }

        int sum=0;

        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])==m.end())
            {
                sum+=(s[i]-'a')+1;
            }
            else
            sum+=m[s[i]];

            if(sum<0)
            {
                sum=0;
            }

            ans=max(ans,sum);
        }

        return ans;
        
    }
};