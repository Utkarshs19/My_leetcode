class Solution {
public:
    int minOperations(string s) {

        set<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')continue;
            st.insert(s[i]);
        }

        vector<char> v;
        for(auto i:st)
        {
            v.push_back(i);
        }
        if(v.size()==0)return 0;
        int ans=0;

        for(int i=1;i<v.size();i++)
        {
            ans+=(v[i]-v[i-1]);
        }
        ans+=('z'-v[v.size()-1]);

        return ans+1;
        
    }
};