class Solution {
public:
    string entityParser(string text) {

        map<string,string> m;

        string ans;

        m[";touq&"]="\"";
        m[";sopa&"]="'";
        m[";pma&"]="&";
        m[";tg&"]=">";
        m[";tl&"]="<";
        m[";lsarf&"]="/";

        stack<char> st;

        int i=0,j=0;

        while(j<text.length())
        {
            if(text[j]=='&')
            {   
                string str="";
                while(j<text.length() && text[j]!=';')
                {
                    st.push(text[j]);
                    j++;
                }
                if(text[j]==';')
                st.push(';');
                
                string s="";
                string t="";
                while(!st.empty())
                {
                    s+=st.top();
                    st.pop();
                    if(m.count(s))
                    {
                        str+=m[s];
                        t+=str;
                        s="";
                    }
                }
                reverse(s.begin(),s.end());
                ans+=s;
                reverse(t.begin(),t.end());
                ans+=t;
            }
            else 
            ans+=text[j];

            j++;
        }

        return ans;
        
    }
};