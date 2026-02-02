class Solution {
public:

    bool check(int n,vector<int> &quantities,int q)
    {
        long long  x=0;

        for(int i=0;i<quantities.size();i++)
        {
            int a=quantities[i]/q;
            int b=quantities[i]%q;
            x+=a;
            if(b>0)
            {
                x++;
            }
        }

        return x<=n;

    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int high=*max_element(quantities.begin(),quantities.end());
        int low=1;

        int ans;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(n,quantities,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }

        return ans;
        
    }
};