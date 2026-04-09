class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        vector<int> v(1e7,0);

        for(int i=0;i<intervals.size();i++)
        {
            v[intervals[i][0]]+=1;
            v[intervals[i][1]+1]-=1;
        }
        int maxi=0;
        for(int i=1;i<v.size();i++)
        {
            v[i]+=v[i-1];
            maxi=max(maxi,v[i]);
        }

        return maxi;
        
    }
};