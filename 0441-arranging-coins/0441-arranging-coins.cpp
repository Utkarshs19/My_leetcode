class Solution {
public:
    int arrangeCoins(int n) {

        long long low=1,high=n,ans;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long coins=(mid*(mid+1))/2;

            if(coins>n)
            high=mid-1;
            else
            {
                ans=mid;
                low=mid+1;
            }

        }   

        return ans;
        
    }
};