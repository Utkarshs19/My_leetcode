class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> v(1000,0);

        for(int i=0;i<trips.size();i++)
        {
            v[trips[i][1]]+=trips[i][0];
            v[trips[i][2]]-=trips[i][0];
        }

        for(int i=1;i<v.size();i++)
        {
            v[i]+=v[i-1];
        }

        int maxi=*max_element(v.begin(),v.end());

        return maxi<=capacity;
        
    }
};