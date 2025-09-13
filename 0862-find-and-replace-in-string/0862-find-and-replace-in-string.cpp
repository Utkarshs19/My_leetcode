class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        int n=s.length();

        vector<int> idx(n,-1);

        for(int i=0;i<indices.size();i++)
        {
            int j=indices[i];

            string str=sources[i];

            if(s.substr(j,str.length())==str)
            idx[j]=i;
        }

        string ans="";

        for(int i=0;i<n;i++)
        {
            if(idx[i]>=0)
            {
                int k=idx[i];
                ans+=targets[k];
                i+=sources[k].length()-1;
            }
            else
            ans+=s[i];
        }
        
        return ans;
    }
};