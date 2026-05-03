class Solution {
public:
    bool isPrime(int n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)cnt++;
        }
        return cnt==2;
    }
    int sumOfPrimesInRange(int n) {

        int low,high;
        int x=n;
        int r=0;
        while(x>0)
        {
            r=r*10+(x%10);
            x=x/10;
        }

        low=min(n,r);
        high=max(n,r);
        int ans=0;
        while(low<=high)
        {
            if(isPrime(low))ans+=low;
            low++;
        }

        return ans;
        
    }
};