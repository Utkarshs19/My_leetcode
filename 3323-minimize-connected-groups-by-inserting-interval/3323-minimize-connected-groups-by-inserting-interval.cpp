class Solution {
public:
    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> new_Intervals;

        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(end>=intervals[i][0])
            {
                end=max(end,intervals[i][1]);
            }
            else
            {
                new_Intervals.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }

        new_Intervals.push_back({start,end});

        for(int i=0;i<new_Intervals.size();i++)
        {
            cout<<new_Intervals[i][0]<<"   "<<new_Intervals[i][1]<<endl;
        }

        vector<int> s,e;

          for(int i=0;i<new_Intervals.size();i++)
        {
            s.push_back(new_Intervals[i][0]);
            e.push_back(new_Intervals[i][1]);
        }

        int ans=new_Intervals.size();

        for(int i=0;i<new_Intervals.size();i++)
        {
            long long val=new_Intervals[i][1]+k;

            int idx=upper_bound(s.begin(), s.end(), val) - s.begin();

            if(idx==s.size())
            {
                ans=min(ans,i+1);
            }
            else
            {
                ans=min(ans,(int)(i+1+(s.size()-idx)));
            }
        }

        return ans;

        
    }
};