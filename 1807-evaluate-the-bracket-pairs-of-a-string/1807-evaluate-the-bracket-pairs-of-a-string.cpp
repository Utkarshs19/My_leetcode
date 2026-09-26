class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        map<string,string> m;
        for(auto i:knowledge)
        {
            m[i[0]]=i[1];
        }


        int i=0,j=0;
        string ans;
        while(j<s.length())
        {
            if(s[j]=='(')
            {
                string str;
                j++;
                while(j<s.length() && s[j]!=')')
                {
                    
                    str+=s[j];
                    j++;
                }
                if(m.count(str))ans+=m[str];
                else ans+='?';
                
            }
            else
            {
                ans+=s[j];
            }
            j++;
        }
        return ans;
    }
};