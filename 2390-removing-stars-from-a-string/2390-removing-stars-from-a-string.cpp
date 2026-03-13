class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }

            if(s[i]=='*')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        int n=st.size();
        string ans;

        for(int i=0;i<n;i++)
        {
            char x=st.top();
            st.pop();
            ans+=x;
        }
        reverse(ans.begin(),ans.end());
return ans;
    }
};