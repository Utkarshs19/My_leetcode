class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        
        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            long long cnt1=0,cnt2=0;
            for(int j=i;j<s.length();j++)
            {
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')cnt1++;
                else cnt2++;

                if(cnt1==cnt2)
                {
                    cout<<i<<"  "<<j<<endl;
                    if((cnt1*cnt2)%k==0)ans++;
                }
            }
        }

        return ans;

    }
};