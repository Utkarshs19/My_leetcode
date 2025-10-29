class Solution {
public:
    int smallestNumber(int n) {


        int k=0;
        int ans=0;

        while(n>0)
        {
            ans=ans+pow(2,k);
            n=n/2;
            k++;
        }
        
        

        return ans;

        
    }
};