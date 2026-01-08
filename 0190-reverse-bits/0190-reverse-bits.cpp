class Solution {
public:
    int reverseBits(int n) {

        long long x=1;
        for(int i=0;i<32;i++)
        x=x*2;

        x--;

        int k=31;

        for (int i = 0; i < 32; i++) 
        {
            if(n%2==0)
            {
                x=x-pow(2,k);
            }
            n=n/2;
            k--;
        }

        return x;

        
    }
};