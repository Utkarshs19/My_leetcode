class Solution {
public:
    bool validDigit(int n, int x) {

        int cnt=0;
        int r;
        while(n>0)
        {
            r=n%10;
            n=n/10;
            if(r==x)cnt++;
        }

        return (cnt>=1 && r!=x);
        
    }
};