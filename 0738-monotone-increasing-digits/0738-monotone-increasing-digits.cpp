class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string str=to_string(n);

        int m=str.length();
        int mark=m;

        for(int i=m-1;i>0;i--)
        {
            if(str[i]<str[i-1])
            {
                str[i-1]--;
                mark=i;
            }
        }

        for(int i=mark;i<m;i++)
        str[i]='9';


        return stoi(str);
        
    }
};