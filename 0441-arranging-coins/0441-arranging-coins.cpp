class Solution {
public:
    int arrangeCoins(int n) {

        int k=1;
        int ans=0;
        while(n>=0)
        {
            if(n>=k)
            {
                ans++;
                n=n-k;
                k++;
            }
            else break;
        }
        return ans;
        
    }
};