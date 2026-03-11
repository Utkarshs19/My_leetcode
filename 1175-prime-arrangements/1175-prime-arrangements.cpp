class Solution {
public:
    int cnt=0;
    const int mod=1e9+7;

    void check(int x)
    {
        bool flag=true;
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)flag=false;
        }
        if(flag)cnt++;
    }

    int numPrimeArrangements(int n) {
        
        for(int i=2;i<=n;i++)
        {
            check(i);
        }

        int n_cnt=n-cnt;

        long long ans=1;

        while(cnt>0)
        {
            ans=(1ll*ans*cnt)%mod;
            cnt--;
        }
        while(n_cnt>0)
        {
            ans=(1ll*ans*n_cnt)%mod;
            n_cnt--;
        }

        
        return ans;

    }
};