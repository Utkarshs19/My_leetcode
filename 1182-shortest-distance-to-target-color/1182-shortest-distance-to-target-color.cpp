class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {

        map<int,vector<int>> m;
        for(int i=0;i<colors.size();i++)
        {
            m[colors[i]].push_back(i);
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++)
        {
            int col=queries[i][1];
            int j=queries[i][0];
            if(!m.count(col))
            {
                ans.push_back(-1);
                continue;
            }
            vector<int> &v=m[col];
            auto idx=lower_bound(v.begin(),v.end(),j);
            int res=INT_MAX;
            if(idx!=v.end())
            {
                res=abs(*idx-j);
            }
            if(idx!=v.begin())
            {
                idx--;
                res=min(res,abs(*idx-j));
            }
            ans.push_back(res);
        }
        return ans;
    }
};