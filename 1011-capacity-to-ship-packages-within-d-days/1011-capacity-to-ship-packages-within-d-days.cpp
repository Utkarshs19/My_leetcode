class Solution {
public:

    int days;

    bool check(vector<int> &weights,int wt)
    {
        int x=1;
        int sum=0;

        for(int i=0;i<weights.size();i++)
        {
            if(sum+weights[i]>wt)
            {
                x++;
                if(weights[i]>wt)return false;
                sum=weights[i];
            }
            else
            {
                sum+=weights[i];
            }
        }

        return x<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum=accumulate(weights.begin(),weights.end(),0);
        this->days=days;
        int ans;
        int low=1,high=sum;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(weights,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return ans;
    }
};