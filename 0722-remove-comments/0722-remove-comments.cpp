class Solution {
public:
    vector<string> removeComments(vector<string>& source) {

        vector<string> ans;

        bool flag=false;

        string s;

        for(int i=0;i<source.size();i++)
        {
            string str=source[i];
            int j=0;
            int n=str.length();
            while(j<n)
            {
                if(!flag && j+1<n && str[j]=='/' && str[j+1]=='*')
                {
                    flag=true;
                    j+=2;
                }
                else if(flag && j+1<n && str[j]=='*' && str[j+1]=='/')
                {
                    flag=false;
                    j+=2;
                }
                else if(!flag && j+1<n && str[j]=='/' && str[j+1]=='/')break;
                else if(!flag)
                {
                    s+=str[j];
                    j++;
                }
                else j++;
            }

            if(!flag && s.size()>0)
            {
                ans.push_back(s);
                s.clear();
            }

        }
        return ans;
    }
};