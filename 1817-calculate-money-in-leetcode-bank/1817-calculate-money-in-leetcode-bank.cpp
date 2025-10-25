class Solution {
public:
    int totalMoney(int n) {

        int k=1;
        int x=1;
        int ans=0;

        int i=1;

        while(i<=n)
        {
            if(i%7==1)
            {
                ans+=k;
                x=k;
                x++;
                k++;
            }
            else
            {
                ans+=x;
                x++;
            }
            i++;
        }

        return ans;
        
    }
};