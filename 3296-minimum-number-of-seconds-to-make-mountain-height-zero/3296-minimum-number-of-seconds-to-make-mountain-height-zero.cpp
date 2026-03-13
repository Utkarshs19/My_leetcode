class Solution {
public:

    bool helper(long long mid,int mountainHeight,vector<int> &workerTimes)
    {
        long long sum = 0;

        for(int i=0;i<workerTimes.size();i++)
        {
            long long l = 0, h = mountainHeight;

            while(l <= h)
            {
                long long k = (l + h) / 2;

                long long time = 1LL * workerTimes[i] * (k * (k + 1) / 2);

                if(time <= mid) l = k + 1;
                else h = k - 1;
            }
            sum += h;

            if(sum >= mountainHeight) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long low=1;
        long long high=1e18;

        long long ans;

        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(helper(mid,mountainHeight,workerTimes))
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