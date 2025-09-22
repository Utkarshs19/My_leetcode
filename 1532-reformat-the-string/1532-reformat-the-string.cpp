class Solution {
public:
    string reformat(string s) {

        string str="";
        string digit="";

        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            digit+=s[i];
            else
            str+=s[i];
        }

        string ans="";

        if(digit.length()>str.length())
        {
            int i=0;
            int j=0;
            while(i<digit.length()&&j<str.length())
            {
                ans+=digit[i];
                ans+=str[j];
                i++;
                j++;
            }
             cout<<"   "<<ans;
            if(digit.length()-i>1)return "";
            else if(i<digit.length())
            ans+=digit[i];
        }   
        else
        {
            int i=0;
            int j=0;
            while(i<digit.length()&&j<str.length())
            {
                ans+=str[j];
                ans+=digit[i];
                i++;
                j++;
            }
            cout<<ans;
            if(str.length()-j>1)return "";
            else if(j<str.length())
            ans+=str[j];
        }

        return ans;
    }
};