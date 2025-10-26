class Solution {
public:
    long long removeZeros(long long n) {

        long long ans=0;

        string s=to_string(n);

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='0')
            {
                ans+=(s[i]-'0');
                ans=ans*10;
            }
        }

        ans=ans/10;

        return ans;
        
    }
};