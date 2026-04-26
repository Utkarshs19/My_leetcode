class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {

        int n=nums.size();

        vector<bool> v(n,false);

        v[0]=true;
        v[n-1]=true;
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>maxi)v[i]=true;
            maxi=max(maxi,nums[i]);
        }
        maxi=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>maxi)v[i]=true;
            maxi=max(maxi,nums[i]);
        }

        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(v[i])ans.push_back(nums[i]);
        }

        return ans;
        
    }
};