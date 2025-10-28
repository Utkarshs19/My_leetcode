class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int n=nums.size();
        int left=0;
        int right=accumulate(nums.begin(),nums.end(),0);

        int ans=0;

        for(int i=0;i<n;i++)
        {
            left+=nums[i];
            right-=nums[i];
            if(nums[i]!=0)continue;
            if(left==right)ans+=2;
            if(abs(left-right)==1)ans+=1;
        }
        
        return ans;
    }
};