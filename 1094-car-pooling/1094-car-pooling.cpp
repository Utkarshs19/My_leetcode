class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        map<int,int> m;
        for(int i=0;i<trips.size();i++)
        {
            m[trips[i][1]]+=trips[i][0];
            m[trips[i][2]]-=trips[i][0];
        }

        int sum=0;
        for(auto i:m)
        {
            sum+=i.second;
            if(sum>capacity)return false;
        }
        return true;
        
    }
};