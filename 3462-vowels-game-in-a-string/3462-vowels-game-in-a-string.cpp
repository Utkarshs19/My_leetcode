class Solution {
public:
    bool doesAliceWin(string s) {
        
        set<char> st;
        int cnt=0;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())cnt++;
        }
        
        if(cnt==0)return false;
        return true;
        
    }
};