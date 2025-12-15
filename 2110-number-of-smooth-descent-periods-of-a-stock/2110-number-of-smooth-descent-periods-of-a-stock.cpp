class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        long long ans=0;

        int j=1;
        int i=0;
        while(j<prices.size())
        {
            if(prices[j-1]-prices[j] == 1)
            {
                j++;
            }
            else
            {
                long long len=j-i;
                ans+=(len*(len+1)/2);
                i=j;
                j++;
            }
        }

        long long len=j-i;
        ans+=(len*(len+1)/2);


        return ans;
        
    }
};