class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        if(k%2==0||k%5==0)return -1;
        long long int n=0;
        for(int i=0;i<k;i++)
        {
            n=(n*10)%k+1;
            if(n%k==0)
            return i+1;
        }

        return -1;


    }
};