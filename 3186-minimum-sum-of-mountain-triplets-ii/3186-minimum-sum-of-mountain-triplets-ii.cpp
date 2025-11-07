class Solution {
public:
    int minimumSum(vector<int>& nums) {

        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suf(n,0);
        int ans=INT_MAX;

        pre[0]=nums[0];
        suf[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        pre[i]=min(pre[i-1],nums[i]);

        for(int i=n-2;i>=0;i--)
        suf[i]=min(suf[i+1],nums[i]);


        for(int i=1;i<n-1;i++)
        {
            if(pre[i-1]>=nums[i])continue;
            if(suf[i+1]>=nums[i])continue;

            ans=min(ans,pre[i-1]+nums[i]+suf[i+1]);
        }

        return ans==INT_MAX?-1:ans;
        
    }
};