class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(),meetings.end());

        int ans=0;

        ans+=meetings[0][0]-1;

        int maxi=meetings[0][1];

        for(int i=1;i<meetings.size();i++)
        {
            if(maxi<meetings[i][0])
            {
                ans+=meetings[i][0]-maxi;
                ans--;
                maxi=max(maxi,meetings[i][1]);
            }
            else
            {
                maxi=max(maxi,meetings[i][1]);
            }

            
        }

        ans+=(days-maxi);

        return ans;
        
    }
};