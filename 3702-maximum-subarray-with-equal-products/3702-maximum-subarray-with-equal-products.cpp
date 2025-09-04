class Solution {
public:
    int maxLength(vector<int>& nums) {

        int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {   
                long long int lcmV=nums[i];
                long long int gcdV=nums[i];
                long long int pro=1;
            for(int j=i;j<nums.size();j++)
            {
                pro=pro*(long long )nums[j];
                if(pro>100000000000)break;
                gcdV=gcd(gcdV,nums[j]);
                lcmV=lcm(lcmV,nums[j]);

                if(pro==(lcmV*gcdV))
                maxi=max(maxi,j-i+1);                
                
            }
        }
        
        return maxi;
    }
};