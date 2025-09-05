class Solution {
public:
    string longestWord(vector<string>& words) {

        map<string,int> m;

        sort(words.begin(),words.end());

        for(int i=0;i<words.size();i++)
        cout<<words[i]<<" ";

        string ans="";

        string str="";

        for(int i=0;i<words.size();i++)
        {
            str=words[i];
            m[words[i]]++;
            string s=words[i];
            int n=s.length();
            if(ans==""&&str.length()==1)
            ans=str;
            if(words[i].length()>1)
            {
                if(m.find(s.substr(0,n-1))!=m.end())
                {
                    if(ans.length()<s.length())
                    ans=s;
                }
                else
                m.erase(s);
                
            }


        }

        return ans;

        
    }
};