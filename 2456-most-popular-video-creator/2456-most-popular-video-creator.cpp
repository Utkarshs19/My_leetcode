class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {

        vector<vector<string>> ans;

        long long maxi=0;

        map<string,pair<int,string>> m1;
        map<string,long long> m;

        for(int i=0;i<creators.size();i++)
        {
            m[creators[i]]+=views[i];
            maxi=max(maxi,m[creators[i]]);
            if(m1.count(creators[i]))
            {
                pair<int,string> p=m1[creators[i]];
                if(p.first<views[i])
                {
                    m1[creators[i]]={views[i],ids[i]};
                }
                else if(p.first==views[i])
                {
                    m1[creators[i]]={views[i],min(p.second,ids[i])};
                }

            }
            else
            {
                m1[creators[i]]={views[i],ids[i]};
            }
        }

        for(auto i:m)
        {
            if(i.second==maxi)
            {
                ans.push_back({i.first,m1[i.first].second});
            }
        }

        return ans;






        
    }
};