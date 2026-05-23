class Solution {
public:
    int lateFee(vector<int>& daysLate) {

        int ans=0;

        for(int i=0;i<daysLate.size();i++)
        {
            if(daysLate[i]==1)ans+=1;
            else if(daysLate[i]>=2 && daysLate[i]<=5)ans+=(2*daysLate[i]);
            else
            ans+=(3*daysLate[i]);
        }
        return ans;
        
    }
};