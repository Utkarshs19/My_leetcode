class Solution {
public:

    bool helper(long long mid,vector<int> &ranks,int cars)
    {
        long long sum=0;

        for(int i=0;i<ranks.size();i++)
        {
            sum+=(sqrt(mid/ranks[i]));
        }

        return sum>=cars;

    }

    long long repairCars(vector<int>& ranks, int cars) {

        long long low=1;
        long long high=1e14;

        long long ans;

        while(low<=high)
        {
            long long mid=low+(high-low)/2;

            if(helper(mid,ranks,cars))
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