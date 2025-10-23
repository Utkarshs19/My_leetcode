class Solution {
public:
    bool hasSameDigits(string s) {

        while(true)
        {
            if(s.length()==2)
            {
                return (s[0]==s[1]);
            }
            else
            {
                string str="";
                for(int i=1;i<s.length();i++)
                {
                    str+=to_string(((s[i-1]-'0')+(s[i]-'0'))%10);
                }
                s=str;
            }

        }
        return false;      
    }
};