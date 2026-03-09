class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        const int MOD=1e9+7;
        long long pro=1;

        int n=nums.size();
        vector<long long> suf(n,1);
        suf[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suf[i]=(suf[i+1]*nums[i])%MOD;
        }

        long long sum=0;

        for(int i=0;i<nums.size();i++)
        {
            if(i==n-1)pro=1;
            else
            pro=suf[i+1];

            if(sum==pro)return i;
            sum=(sum+nums[i])%MOD;
        }
        return -1;
        
    }
};