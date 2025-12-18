class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

        long long ans=0;
        int n=prices.size();

        vector<long long int> pre(n);
        vector<long long int> suf(n);

        pre[0]=prices[0]*strategy[0];
        suf[n-1]=prices[n-1]*strategy[n-1];

        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+prices[i]*strategy[i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+prices[i]*strategy[i];
        }

        ans=pre[n-1];      
        
        for (int i = 0; i + k <= n; i++)
    {
        long long x = 0;

        int mid = i + (k - 1) / 2;

        for (int j = mid + 1; j < i + k; j++)
            x += prices[j];

        if (i - 1 >= 0) x += pre[i - 1];
        if (i + k < n)  x += suf[i + k];

         ans = max(ans, x);
    }
        return ans;
    }
};