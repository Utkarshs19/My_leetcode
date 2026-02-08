class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        
        int ans=0;
        int sum=0;
        int n=nums.size()-1;

        for(int i=nums.size()-2;i>=0;i--)
        {
            sum+=nums[i+1];

            if(nums[i]>((sum*1.0)/(n-i)))ans++;
        }

        return ans;

        
    }
};