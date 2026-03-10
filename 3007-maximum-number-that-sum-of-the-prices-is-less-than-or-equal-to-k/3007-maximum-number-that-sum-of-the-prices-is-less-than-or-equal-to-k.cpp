class Solution {
public:
    map<long long,int> m;

    bool helper(long long mid,long long k,int x)
    {
        long long sum=0;

        for(int i=0;i<60;i++)
        {   
            if((i+1)%x==0)
            {
               long long cycle = 1LL<<(i+1);
                long long full = mid/cycle;

                long long ones = full*(1LL<<i);

                long long rem = mid%cycle;

                ones += max(0LL, rem-(1LL<<i)+1);

                sum += ones;

                if(sum>k) return false;
            }
        }

        m[mid]=sum;

        return sum<=k;
    }

    long long findMaximumNumber(long long k, int x) {

        long long high=1e18;
        long long low=1;
        long long ans;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;

            if(helper(mid,k,x))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;        
    }
};