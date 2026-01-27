class Solution {
public:
    string reorderSpaces(string text) {

        vector<string> v;
        int x=0,y=0;

        int i=0;
        while(i<text.length())
        {
            if(text[i]==' ')x++;
            else if(text[i]!=' ')
            {
                string str="";
                while(i<text.length() && text[i]!=' ')
                {
                    str+=text[i];
                    i++;
                }
                i--;
                v.push_back(str);
            }
            i++;
        }
        
        if(v.size()==1)
        {
            string ans;
            ans+=v[0];
            string s(x,' ');
            ans+=s;
            return ans;
        }

        y=x%(v.size()-1);
        x=x/(v.size()-1);

        string ans;
        for(int i=0;i<v.size()-1;i++)
        {
            ans+=v[i];
            string s(x,' ');
            ans+=s;
        }
        ans+=v[v.size()-1];
        string s(y,' ');
        ans+=s;

        return ans;
        
    }
};