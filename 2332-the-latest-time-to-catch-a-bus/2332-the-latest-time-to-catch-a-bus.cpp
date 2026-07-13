class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {

        int i=0,j=0;
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        unordered_set<int> vis;

        int ans=0;

       for(int i=0;i<buses.size();i++)
        {
            int c=0;
           while(c<capacity && j<passengers.size() && passengers[j]<=buses[i])
           {
                if(!vis.count(passengers[j]-1))ans=passengers[j]-1;
                vis.insert(passengers[j]);
                c++;
                j++;
           }

           if(c<capacity && !vis.count(buses[i]))
           ans=buses[i];
        }
        return ans;

        
    }
};