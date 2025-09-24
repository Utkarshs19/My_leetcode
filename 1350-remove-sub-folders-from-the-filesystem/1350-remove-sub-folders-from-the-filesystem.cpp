class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        vector<string> ans;

        sort(folder.begin(),folder.end());

        map<string,int> m;

        string str="";

        for(int i=0;i<folder.size();i++)
        {
            
            if(m.find(folder[i].substr(0,str.length()))!=m.end())
            {
                if(folder[i].length()==str.length())
                continue;
                else
                {
                    if(folder[i][str.length()]=='/')continue;
                    else
                    {
                        m[folder[i]]++;
                        str=folder[i];
                        ans.push_back(str);
                    }
                }

            }
            else
            {
                m[folder[i]]++;
                str=folder[i];
                ans.push_back(str);
            }
           
        }

        // for(auto i:m)
        // {
        //     ans.push_back(i.first);
        // }

        return ans;

    }
};