class Solution {
public:

    bool helper(int mid,vector<int> &bloomDay,int m,int k)
    { 
        int cnt=0,cnt1=0;

        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)cnt1++;
            else{
            cnt+=(cnt1/k);
            cnt1=0;
            }
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