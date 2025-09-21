class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string ans="";

        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(!st.empty()&&s[i]==')'&&st.top()=='(')
           { ans+=s[i];
           st.pop();
           continue;
           }

            if(st.empty()&&s[i]==')')continue;

            ans+=s[i];

            if(s[i]=='(')st.push(s[i]);
        }   

        int keep=st.size();

        string res="";

        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]=='('&&keep)
            {
                keep--;
                continue;
            }
            res+=ans[i];
        }

        reverse(res.begin(),res.end());

        return res;
        
    }
};