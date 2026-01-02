class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

        vector<string> ans;

        map<string,int> m;

        for(int i=0;i<names.size();i++)
        {
            if(m.find(names[i])==m.end())
            {
                m[names[i]]=1;
                ans.push_back(names[i]);
            }
            else
            {
                int k=m[names[i]];
                while(true)
                {
                    string s=names[i];
                    s+='(';
                    s+=to_string(k);
                    s+=')';

                    if(m.find(s)==m.end())
                    {
                        ans.push_back(s);
                        m[names[i]]=k+1;
                        m[s]=1;
                        break;
                    }
                    k++;
                }
            }
        }

        return ans;
        
    }
};