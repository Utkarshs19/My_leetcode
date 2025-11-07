class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        vector<int> pre(nums.size(),0);
        vector<int> suf(nums.size(),0);
        int n=nums.size();
        long long ans=0;

        pre[0]=nums[0];
        suf[n-1]=nums[n-1];

        for(int i=1;i<nums.size();i++)
        {
            pre[i]=max(pre[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            suf[i]=max(suf[i+1],nums[i]);
        }

        for(int j=1;j<n-1;j++)
        {  
            ans=max(ans,(long long)(pre[j-1]-nums[j])*(suf[j+1]));
        }

        return ans;

    }
};