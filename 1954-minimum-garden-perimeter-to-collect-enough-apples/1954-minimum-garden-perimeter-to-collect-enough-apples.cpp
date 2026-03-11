class Solution {
public:

    bool helper(long long mid,long long neededApples)
    {
        long long cnt=2ll*mid*(mid+1)*(2*mid+1);    

        return cnt>=neededApples;

    }

    long long minimumPerimeter(long long neededApples) {

        long long low=1;
        long long high=1e6;

        long long ans;

        while(low<=high)
        {
            long long mid=low+(high-low)/2;

            if(helper(mid,neededApples))
            {
                ans=8*mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }

        return ans;
        
    }
};