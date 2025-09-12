class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

       

        vector<int> ans(intervals.size(),-1);

        map<pair<int,int>,int> m;

        for(int i=0;i<intervals.size();i++)
        {
            m[{intervals[i][0],intervals[i][1]}]=i;
        }

        for(auto i:m)
        {
            cout<<i.first.first<<" "<<i.first.second<<"--->"<<i.second<<endl;
        }

        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            for(int j=i;j<intervals.size();j++)
            {
                if(end<=intervals[j][0])
                {
                    ans[m[{start,end}]]=m[{intervals[j][0],intervals[j][1]}];
                    break;
                }
            }
        }
        
        return ans;
    }
};