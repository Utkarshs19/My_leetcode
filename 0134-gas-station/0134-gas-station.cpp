class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int start=0;
        int sum=0;
        int total=0;

        for(int i=0;i<gas.size();i++)
        {
            int diff=gas[i]-cost[i];
            sum+=diff;
            total+=diff;
            if(sum<0)
            {
                sum=0;
                start=i+1;
            }
        }

        return total>=0?start:-1;
        
    }
};