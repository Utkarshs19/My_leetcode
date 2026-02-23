class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<pair<char,int>> st;
        int ans=0;
        int n=s.length();

        for(int i=0;i<s.length();i++)
        {
            if(st.empty())
            {
                st.push({s[i],i});
            }
            else if(s[i]==')' && st.top().first=='(')st.pop();
            else
            st.push({s[i],i});
        }
        if(st.size()==0)return s.length();
        while(!st.empty())
        {
            ans=max(ans,n-st.top().second-1);
            n=st.top().second;
            st.pop();
        }
        ans=max(ans,n);

        return ans;

    }
};