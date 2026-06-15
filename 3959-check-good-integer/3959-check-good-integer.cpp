class Solution {
public:
    bool checkGoodInteger(int n) {

        long long sum=0;
        long long squareSum=0;

        while(n>0)
        {
            int x=n%10;
            n=n/10;
            sum+=x;
            squareSum+=(1ll*x*x);
        }

        return squareSum-sum>=50;
        
    }
};