class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int maxi=-1e9;

        vector<long long> v;

        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);

            v.push_back(gcd(nums[i],maxi));
        }
        sort(v.begin(),v.end());
        int i=0,j=v.size()-1;

        long long sum=0;

        while(i<j)
        {
            sum+=gcd(v[i],v[j]);
            i++;
            j--;
        }

        return sum;
        
    }
};