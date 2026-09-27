class Solution {
public:
    string reverseParentheses(string s) {
        
        string ans="";

        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
            {   
                string rev="";
                while(st.top()!='(')
                {
                    rev+=st.top();
                    st.pop();
                }
                
                st.pop();
                for(int j=0;j<rev.length();j++)
                st.push(rev[j]);
            }
            else st.push(s[i]);
        }


        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};