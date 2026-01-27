class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        
        double ans=0.0;

        int x=min(income,brackets[0][0]);
        ans+=(x*((1.0 * brackets[0][1])/100));
        income=income-x;

        for(int i=1;i<brackets.size();i++)
        {
            int x=min(income,(brackets[i][0]-brackets[i-1][0]));
            ans+=(x*((1.0 * brackets[i][1])/100));
            income=income-x;
            
            if(income<=0)break;
        }

        return ans;

    }
};