class Solution {
public:
    int numSplits(string s) {

        map<char,int> m;

        for(auto i:s)
        m[i]++;

        set<char> st;
        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
            m[s[i]]--;
            if(m[s[i]]==0)m.erase(s[i]);

            if(m.size()==st.size())ans++;
        }

        return ans;
        
    }
};