class Solution {
public:
    int k=0;
    int ans=0;
   
    int bitwiseComplement(int n) {
         if(n==0)return 1;
        while(n>0)
        {
            if(n%2==0)
            ans+=(pow(2,k));
            k++;
            n=n/2;
        }
        return ans;
        
    }
};