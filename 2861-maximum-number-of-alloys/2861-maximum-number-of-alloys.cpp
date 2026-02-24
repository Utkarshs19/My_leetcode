class Solution {
public:

    bool helper(long long mid,vector<int> comp,vector<int> stock,vector<int> &cost,int budget)
    {
        long long x=0;
        long long y=0;

        for(int i=0;i<comp.size();i++)
        {
            y=comp[i]*mid;
            if(y>stock[i]){
            y=y-stock[i];
            x+=(y*cost[i]);
            }
        }
        return x<=budget;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long ans=0;

        for(int i=0;i<composition.size();i++)
        {
            long long low=0,high=1e10;
            while(low<=high)
            {
                long long mid=low+(high-low)/2;

                if(helper(mid,composition[i],stock,cost,budget))
                {
                    ans=max(ans,mid);
                    low=mid+1;
                }
                else
                high=mid-1;
            }
        }

        return ans;
        
    }
};