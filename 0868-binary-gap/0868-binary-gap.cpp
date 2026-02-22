class Solution {
public:
    int binaryGap(int n) {

        int ans=0;
        int prev=-1;
        int k=0;

        while(n>0)
        {
            if(n%2==1)
            {
                if(prev==-1)
                prev=k;
                else
                {
                    ans=max(ans,k-prev);
                    prev=k;
                }
            }
            n=n/2;
            k++;
        }
        return ans;
        
    }
};