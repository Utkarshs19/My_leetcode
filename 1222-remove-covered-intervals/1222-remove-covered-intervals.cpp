class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        int ans=0;


        for(int i=0;i<intervals.size();i++)
        cout<<intervals[i][0]<<"  "<<intervals[i][1]<<endl;
        
        int i=0;
        while(i<intervals.size())
        {
            int x1=intervals[i][0];
            int y1=intervals[i][1];

            int k=i+1;
            while(k<intervals.size() && x1==intervals[k][0])
            {
                y1=max(y1,intervals[k][1]);
                k++;
            }
            if(k!=i+1)
            i=k;

            int j=i+1;

            while(j<intervals.size() && y1>=intervals[j][1])
            {
                j++;
            }
            ans++;
            i=j;
        }

        return ans;
        
    }
};