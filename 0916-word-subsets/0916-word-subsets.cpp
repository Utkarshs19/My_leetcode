class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<string> ans;

        map<char,int> m;

        for(int i=0;i<words2.size();i++)
        {
            map<char,int> m1;
            for(int j=0;j<words2[i].length();j++)
            {
                m1[words2[i][j]]++;
            }

            for(auto k:m1)
            {
                if(m[k.first]==0)
                {
                    m[k.first]=k.second;
                }
                else
                m[k.first]=max(m[k.first],k.second);
            }
        }

        for(int i=0;i<words1.size();i++)
        {
            map<char,int> m1;
            for(int j=0;j<words1[i].length();j++)
            m1[words1[i][j]]++;

            bool flag=true;
            
            for(auto k:m)
            {
                if(m1[k.first]<m[k.first])
                {
                    flag=false;
                    break;
                }
            }

            if(flag)ans.push_back(words1[i]);

        }

        return ans;


        
    }
};