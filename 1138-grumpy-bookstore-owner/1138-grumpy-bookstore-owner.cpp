class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int ans=-1;
        int sum=0;

        for(int i=0;i<customers.size();i++)
        {
            if(i<=minutes-1)
            {
                sum+=customers[i];
            }
            else
            {
                if(grumpy[i]==0)
                sum+=customers[i];
            }
        }
        ans=max(ans,sum);

        int i=0,j=minutes;

        while(j<customers.size())
        {
            if(grumpy[i]==1)
            sum=sum-customers[i];
            if(grumpy[j]==1)
            sum+=customers[j];

            i++;
            j++;
            ans=max(ans,sum);
        }

        return ans;
    }
};