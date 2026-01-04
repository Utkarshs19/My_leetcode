class Solution {
public:
    string largestEven(string s) {

        int i=s.length()-1;

        while(i>=0)
        {
            if(s[i]=='1')
            {
                i--;
            }
            else break;
        }

        return s.substr(0,i+1);
        
    }
};