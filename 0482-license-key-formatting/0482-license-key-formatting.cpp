class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        string ans="";

        string str="";

        int i=0;
        while(i<s.length())
        {
            if(isalpha(s[i]))
            str+=toupper(s[i]);

            if(isdigit(s[i]))
            str+=s[i];

            i++;
        }
        

        if(str.length()%k==0)
        {
            int i=0;
            while(i<str.length()){
            ans+=str.substr(i,k);
            ans+='-';

            i=i+k;}
        }
        else
        {
            int i=0;
            ans+=str.substr(i,str.length()%k);
            ans+='-';
            i=str.length()%k;

            while(i<str.length())
            {
                ans+=str.substr(i,k);
                ans+='-';

                i=i+k;
            }
        }


        return ans.substr(0,ans.length()-1);
    }
};