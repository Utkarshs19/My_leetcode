class Solution {
public:
    char kthCharacter(int k) {

        string s="a";

        while(s.length()<k)
        {
            string str=s;
            int i=0;
            while(i<str.length())
            {
                if(str[i]=='z')str[i]='a';
                else
                str[i]=str[i]+1;
                i++;
            }
            s+=str;
        }

        return s[k-1];
        
    }
};