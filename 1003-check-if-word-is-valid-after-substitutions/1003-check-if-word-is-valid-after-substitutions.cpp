class Solution {
public:
    bool isValid(string s) {
        
        string str;

        for(int i=0;i<s.length();i++)
        {
            str+=s[i];

            if(str.length()>=3)
            {
                int len=str.length();
                if(str[len-1]=='c' && str[len-2]=='b' && str[len-3]=='a')
                {
                    str.pop_back();
                    str.pop_back();
                    str.pop_back();
                }
            }
        }

        return str.length()==0;

    }
};