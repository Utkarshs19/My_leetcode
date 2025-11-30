class Solution {
public:
    int maxDistinct(string s) {
        set<char> st;
        for(auto i:s)
        st.insert(i);

        return st.size();
        
    }
};