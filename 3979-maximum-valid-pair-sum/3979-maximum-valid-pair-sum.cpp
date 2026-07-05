class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        
        int n=nums.size();

        vector<int> suf(n);
        suf[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suf[i]=max(nums[i],suf[i+1]);
        }
        long long ans=0;
        for(int i=0;i<n-k;i++)
        {
            ans=max(ans,1ll*(nums[i]+suf[i+k]));
        }
        return ans;
        
    }
};