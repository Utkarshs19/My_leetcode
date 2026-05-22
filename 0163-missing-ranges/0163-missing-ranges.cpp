class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        vector<vector<int>> ans;
        int n=nums.size();
        if(nums.size()==0)return {{lower,upper}};
        if(lower!=nums[0])ans.push_back({lower,nums[0]-1});

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]+1!=nums[i])
            {
                ans.push_back({nums[i-1]+1,nums[i]-1});
            }
        }

        if(nums[n-1]!=upper)
        ans.push_back({nums[n-1]+1,upper});

        return ans;
        
    }
};