class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n==0)return 0;

        long long sum=0;

        string str=to_string(n);
        string s="";

        for(int i=0;i<str.length();i++)
        {
            if(str[i]!='0')
            {
                sum+=(str[i]-'0');
                s+=str[i];
            }
        }

        long long no=stoi(s);

        return no*sum;
        
    }
};