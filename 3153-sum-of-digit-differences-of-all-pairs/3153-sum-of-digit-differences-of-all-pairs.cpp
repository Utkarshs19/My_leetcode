class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {

        long long ans=0;

        int x=nums[0];
        int n=0;
        while(x>0)
        {
            n++;
            x=x/10;
        }

        for(int i=0;i<n;i++)
        {
            vector<int> v(10,0);
            for(int j=0;j<nums.size();j++)
            {
                v[nums[j]%10]++;
                nums[j]=nums[j]/10;
            }
            
            for(int k=0;k<v.size();k++)
            {
                for(int k1=k+1;k1<v.size();k1++)
                {
                    ans+=(1ll*v[k]*v[k1]);
                }
            }
        }

        return ans;
        
    }
};