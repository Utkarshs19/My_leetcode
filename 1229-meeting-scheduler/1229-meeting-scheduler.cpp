class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());

        int i=0,j=0;
        int n=slots1.size();
        int m=slots2.size();

        while(i<n && slots1[i][1]<slots2[j][0])i++;

        vector<vector<int>> common;
        int start=-1,end=1e9;
        while(i<n && j<m)
        {
             start=max({start,slots1[i][0],slots2[j][0]});
             end=min(slots1[i][1],slots2[j][1]);

            common.push_back({start,end});
            if(end==slots1[i][1]){
            start=slots1[i][1];
                i++;
            }
            if(end==slots2[j][1])
            {
                slots2[j][1];
                j++;
            }
        }

        for(int i=0;i<common.size();i++)
        {
            if(common[i][1]-common[i][0]>=duration)
            return {common[i][0],common[i][0]+duration};
        }

        return {};

    }
};