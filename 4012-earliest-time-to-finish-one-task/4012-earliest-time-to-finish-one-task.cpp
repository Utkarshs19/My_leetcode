class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {

        vector<int> v;

        int  mini=INT_MAX;

        for(int i=0;i<tasks.size();i++)
        {
            mini=min(mini,(tasks[i][0]+tasks[i][1]));
        }

        return mini;
        
    }
};