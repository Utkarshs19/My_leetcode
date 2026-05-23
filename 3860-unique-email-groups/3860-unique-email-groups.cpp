class Solution {
public:
    int uniqueEmailGroups(vector<string>& emails) {

        set<string> st;

        for(int i=0;i<emails.size();i++)
        {
            string str=emails[i];
            int idx;

            for(int j=0;j<str.length();j++)
            {
                if(isalpha(str[j]))
                {
                    str[j]=tolower(str[j]);
                }
                if(str[j]=='@'){
                idx=j;
                }
            }

            string s2=str.substr(idx);
            string s1;
            int k=0;
            while(k<idx)
            {
                if(str[k]=='.'){
                    k++;
                    continue;
                }
                else if(str[k]=='+')break;
                else
                s1+=str[k];

                k++;
            }

            s1+=s2;
            st.insert(s1);
            
        }
        return st.size();
    }
};