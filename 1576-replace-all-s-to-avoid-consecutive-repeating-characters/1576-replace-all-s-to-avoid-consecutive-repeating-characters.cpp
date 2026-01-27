class Solution {
public:
    string modifyString(string s) {

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {   
                char c1='?',c2='?';
                if(i-1>=0){
                    c1=s[i-1];
                }
                if(i+1<s.length())
                {
                    c2=s[i+1];
                }

                for(int j=0;j<26;j++)
                {
                    if('a'+j==c1 || 'a'+j==c2)continue;
                    else
                    {
                        s[i]=j+'a';
                        break;
                    }
                }
            }
        }

        return s;
        
    }
};