class Solution {
public:
    long long sumAndMultiply(int n) {

        long long x=0,sum=0;
        string str=to_string(n);
        for(int i=0;i<str.length();i++)
        {
            int y=str[i]-'0';
            if(y!=0)
            {
                sum+=y;
                x=x*10+y;
            }
            n=n/10;
        }
        return sum*x;
        
    }
};