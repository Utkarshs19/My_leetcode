class Solution {
public:

    bool helper(int x)
    {
        int cnt=0;
        while(x>0)
        {
            if(x%2==1)cnt++;
            x=x/2;
        }
        int cnt1=0;
        for(int i=1;i<=cnt;i++)
        {
            if(cnt%i==0)cnt1++;
        }

        return cnt1==2;
    }

    int countPrimeSetBits(int left, int right) {

        int ans=0;

        for(int i=left;i<=right;i++)
        {
            if(helper(i))ans++;
        }
        return ans;

    }
};