class Solution {
public:
    bool canConvertString(string s, string t, int k) {

        set<int> st;

        if(s.length()!=t.length())return false;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])
            {
                int x=t[i]-s[i];
                if(x<0)
                x=x+26;
                while(st.count(x) && x<=k)
                {
                    x=x+26;
                }
                if(x>k)return false;
                else 
                st.insert(x);
                cout<<x<<"  "<<i<<endl;
            }
        }

        return true;
        
    }
};