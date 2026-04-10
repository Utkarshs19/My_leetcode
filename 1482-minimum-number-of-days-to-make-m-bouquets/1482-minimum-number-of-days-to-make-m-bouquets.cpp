class Solution {
public:

    bool helper(int mid,vector<int> &bloomDay,int m,int k)
    {
        vector<int> v(bloomDay.size(),0);

        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)v[i]=1;
        }

        int cnt=0;

        int i=0,j=0;
        int cnt1=0;
        while(j<v.size())
        {
            if(v[j]==1)cnt1++;
            else
            {
                cnt+=(cnt1/k);
                cnt1=0;
            }
            j++;
        }
        cnt+=(cnt1/k);
        return cnt>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int low=1;
        int high=1e9;
        int ans=-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(helper(mid,bloomDay,m,k))
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