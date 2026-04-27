class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        vector<pair<int,int>> v;
        vector<int> v1,v2;
        for(int i=0;i<items.size();i++)
        {
            v.push_back({items[i][0],items[i][1]});
        }
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++)
        {
            v1.push_back(v[i].first);
            if(v2.empty())v2.push_back(v[i].second);
            else
            {
                v2.push_back(max(v2.back(),v[i].second));
            }
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++)
        {
            auto idx=upper_bound(v1.begin(),v1.end(),queries[i]);
            if(idx==v1.begin())
            ans.push_back(0);
            else{
                int i=idx-v1.begin();
            ans.push_back(v2[i-1]);}
        }
        return ans;
        
    }
};