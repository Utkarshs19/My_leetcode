class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());

        int i=0,j=0;
        int n=slots1.size();
        int m=slots2.size();

        while(i<n && slots1[i][1]<slots2[0][0])i++;

        int start=-1,end=1e9;
        while(i<n && j<m)
        {
             start=max({start,slots1[i][0],slots2[j][0]});
             end=min(slots1[i][1],slots2[j][1]);

                if(end-start>=duration)return {start,start+duration};
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

        return {};

    }
};