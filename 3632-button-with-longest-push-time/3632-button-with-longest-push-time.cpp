class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {

        int ans=events[0][0];
        int x=events[0][1];

        for(int i=1;i<events.size();i++)
        {
            if(x<events[i][1]-events[i-1][1])
            {
                x=events[i][1]-events[i-1][1];
                ans=events[i][0];
            }
            else if(x==events[i][1]-events[i-1][1])
            {
                ans=min(ans,events[i][0]);
            }

        }

        return ans;
        
    }
};