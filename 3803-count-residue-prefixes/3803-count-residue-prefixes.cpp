class Solution {
public:
    int residuePrefixes(string s) {

        int ans=0;

        set<int> st;

        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
            if(st.size()==(i+1)%3)ans++;
        }

        return ans;
        
    }
};