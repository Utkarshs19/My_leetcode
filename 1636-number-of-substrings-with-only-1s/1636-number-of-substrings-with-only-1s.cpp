class Solution {
public:
    int numSub(string s) {

        int i=0,j=0;
        long long ans=0;

        while(j<s.length())
        {
             if(s[j]=='0')
             {
                i++;
                j++;
             }
             else
             {
                while(j<s.length() && s[j]=='1')
                j++;

                long long diff = j - i;
                long long y = diff * (diff + 1) / 2;
                ans+=y;
                ans=ans%(1000000007);
                i=j;
             }
        }

        return ans;
        
    }
};