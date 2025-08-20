class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        
        vector<set<string>> v;

        for(int i=0;i<responses.size();i++)
        {   
            set<string> s;
            for(int j=0;j<responses[i].size();j++)
            {
                s.insert(responses[i][j]);
            }
            v.push_back(s);
        } 

        map<string,int> m;

        for(int i=0;i<v.size();i++)
        {
            set s=v[i];
            for(auto i:s)
            {
                m[i]++;
            }
        }

        int maxi=0;

        for(auto i:m)
        {
            maxi=max(maxi,i.second);
        }

        for(auto i:m)
        {
            if(i.second==maxi)return i.first;
        }

        return "";
    }
};