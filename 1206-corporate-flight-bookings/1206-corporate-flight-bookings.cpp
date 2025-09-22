class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> ans(n,0);

        for(int i=0;i<bookings.size();i++)
        {
            int k=bookings[i][0];

            while(k<=bookings[i][1])
            {
                ans[k-1]+=bookings[i][2];
                k++;
            }
        }

        return ans;
        
    }
};