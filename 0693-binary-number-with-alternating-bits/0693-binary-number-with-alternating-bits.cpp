class Solution {
public:
    bool hasAlternatingBits(int n) {

        int x=n%2;

        n=n/2;

        while(n>0)
        {
            if(x==n%2)return false;
            x=n%2;
            n=n/2;
        }

        return true;
        
    }
};