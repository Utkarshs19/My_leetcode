class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        long long ans=0;
        int n=nums.size();
        vector<bool> flag(n,false);

        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(flag[i]==true)continue;
            else
            {
                ans+=nums[i];
                flag[i]=true;
            }
            for(int j=i+1;j<n;j++)
            {
                if(flag[j])continue;
                
                if(nums[j]%nums[i]==0)
                {
                    ans+=nums[i];
                    flag[j]=true;
                }
            }
        }
        
        return ans;
    }
};