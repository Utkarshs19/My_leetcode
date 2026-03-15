class Solution {
public:
    int countCommas(int n) {
        
        int sum=0;

        if(n<=999)
        return 0;

        int cnt=(min(100000,n)-1000);

        if(cnt+1<0)return sum;
        else
        {
            sum+=cnt+1;
        }

        return sum;

    }
};