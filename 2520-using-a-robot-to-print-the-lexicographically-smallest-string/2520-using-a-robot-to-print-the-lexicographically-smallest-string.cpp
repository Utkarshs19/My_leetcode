class Solution {
public:
    char helper(map<char,int>& m)
    {
        for(auto i:m)
        {
            if(i.second)
            return i.first;
        }
        return 'a';
    }
    string robotWithString(string s) {

        string t="";
        string ans="";

        map<char,int> m;
        for(auto i:s)
        m[i]++;

        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            st.push(s[i]);
            m[s[i]]--;
            
            while(!st.empty()&& st.top()<=helper(m))
            {
                ans+=st.top();
                st.pop();
            }
        }

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }



        return ans;
        
    }
};