class Solution {
public:
    string maskPII(string s) {

        
        if(isdigit(s[s.length()-1])||s[0]=='+'||isdigit(s[0])||s[0]=='(')
        {
            string str="";
            for(int i=0;i<s.length();i++)
            {
                if(isdigit(s[i]))
                str+=s[i];
            }
            int len=str.length();
            string xyz="";
            xyz+=str[len-1];
            xyz+=str[len-2];
            xyz+=str[len-3];
            xyz+=str[len-4];
            reverse(xyz.begin(),xyz.end());

            string ans="";
            if(str.length()==10){
            ans+="***-***-";
            ans+=xyz;
            }
            if(str.length()==11){
            ans+="+*-***-***-";
            ans+=xyz;}
            if(str.length()==12){
            ans+="+**-***-***-";
            ans+=xyz;}
            if(str.length()==13){
            ans+="+***-***-***-";
            ans+=xyz;}

            return ans;
        }
        else
        {
            for(int i=0;i<s.length();i++)
            {
                if(isalpha(s[i]))
                s[i]=tolower(s[i]);
            }

            string email="";
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='@')
                {
                    email+=s[0];
                    email+="*****";
                    email+=s[i-1];
                    email+=s.substr(i);
                    break;
                }
            }
            return email;
        }
        
    }
};