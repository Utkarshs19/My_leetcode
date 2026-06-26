class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.length();
        vector<long long> pre0(n,0);
        vector<long long> pre1(n,0);
        if(s[0]=='0')pre0[0]=1;
        if(s[0]=='1')pre1[0]=1;

        for(int i=1;i<n;i++)
        {
            if(s[i]=='1')
            {
                pre1[i]=1+pre1[i-1];
            }
            else
            pre1[i]=pre1[i-1];

            if(s[i]=='0')
            {
                pre0[i]=1+pre0[i-1];
            }
            else
            pre0[i]=pre0[i-1];
        }

        vector<long long> pre01(n,0),pre10(n,0);

        for(int i=1;i<n;i++)
        {
            if(s[i]=='1')
            {
                pre01[i]=pre0[i-1];
            }
            if(s[i]=='0')
            {
                pre10[i]=pre1[i-1];
            }
        } 

        long long ans=0;

        for(int i=1;i<n;i++)
        {
            int cnt0=pre0[n-1]-pre0[i];
            ans+=(pre01[i]*cnt0);
            int cnt1=pre1[n-1]-pre1[i];
            ans+=(pre10[i]*cnt1);
        }

        return ans;
        
    }
};