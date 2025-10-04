class Solution {
public:
    long long maxScore(vector<int>& nums) {
        
        long long ans=0;

        if(nums.size() == 1) return (long long)nums[0]*nums[0];

        for(int i=0;i<nums.size();i++)
        {   
            vector<int> v;
            for(int j=0;j<nums.size();j++)
            {
                if(i==j)continue;
                v.push_back(nums[j]);
            }

            long long gcd = v[0];
            long long lcm = v[0];

            for(int k=1; k<v.size(); k++) {
                gcd = __gcd(gcd, (long long)v[k]);
                lcm = lcm / __gcd(lcm, (long long)v[k]) * v[k];
            }

            ans = max(ans, gcd * lcm);

        }

        long long gcd=nums[0];
        long long lcm=nums[0];

         for(int k=1; k<nums.size(); k++) {
                gcd = __gcd(gcd, (long long)nums[k]);
                lcm = lcm / __gcd(lcm, (long long)nums[k]) * nums[k];
            }

            ans = max(ans, gcd * lcm);


        return ans;

    }
};