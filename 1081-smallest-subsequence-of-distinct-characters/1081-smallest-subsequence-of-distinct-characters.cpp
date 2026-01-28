class Solution {
public:
    string smallestSubsequence(string s) {

        vector<bool> instack(26);
        vector<int> freq(26);

        for(auto c:s)
        {
            freq[c-'a']++;
        }

        stack<char> st;
        for(auto c:s)
        {
            freq[c-'a']--;
            if(instack[c-'a'])continue;

            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0)
            {
                instack[st.top()-'a']=false;
                st.pop();
            }

            instack[c-'a']=true;
            st.push(c);
        }

        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};