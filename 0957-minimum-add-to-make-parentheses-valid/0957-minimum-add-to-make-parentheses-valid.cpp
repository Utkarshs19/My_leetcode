class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;

        int cnt=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')'&&!st.empty()&&st.top()=='(')
            st.pop();
            else if(s[i]==')')
            st.push(')');
            else
            st.push('(');
        }
        

        return st.size();
    }
};