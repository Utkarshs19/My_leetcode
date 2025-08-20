class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        
        map<string,int> m;

        for(int i=0;i<responses.size();i++)
        {   
            set<string> s;
            for(int j=0;j<responses[i].size();j++)
            {
                s.insert(responses[i][j]);
            }
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