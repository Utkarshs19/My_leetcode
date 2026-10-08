class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans;
        int open=0,close=0;
        int i=0,j=0;
        while(j<s.length())
        {
            if(s[j]=='(')open++;
            else close++;

            if(open==close)
            {
                ans+=s.substr(i+1,j-i-1);
                i=j+1;
                open=0;
                close=0;
            }
            j++;
        }

        return ans;
        
    }
};