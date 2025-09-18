class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        set<string> st;

        for(int i=0;i<emails.size();i++)
        {
            string str=emails[i];

            int j=0;

            while(j<str.length())
            {
                if(str[j]=='@')
                break;

                j++;
            }
            string s="";

            for( int k=0;k<j;k++)
            {
                if(str[k]=='.')
                continue;
                else if(str[k]=='+')break;
                else
                s+=str[k];

            }

            s+=str.substr(j);
            st.insert(s);
        }
        

        return st.size();
    }
};