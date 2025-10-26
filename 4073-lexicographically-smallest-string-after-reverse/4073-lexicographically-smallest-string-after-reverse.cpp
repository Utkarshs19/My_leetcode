class Solution {
public:
    string helper(string str)
    {
        reverse(str.begin(),str.end());
        return str;
    }
    string lexSmallest(string s) {
        
        string ans=s;

        string str="";
        for(int i=1;i<s.length();i++)
        {
            str+=helper(s.substr(0,i));
            str+=s.substr(i);
            ans=min(ans,str);
            str="";
            str+=s.substr(0,i);
            str+=helper(s.substr(i));
            ans=min(ans,str);
            str="";
        }

        reverse(s.begin(),s.end());
        ans=min(ans,s);

        return ans;


    }
};

