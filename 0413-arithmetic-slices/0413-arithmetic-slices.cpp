class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int ans=0;
        int n=nums.size();

        for(int i=0;i<=n-3;i++)
        {
            int x=nums[i+1]-nums[i];
            for(int j=i+2;j<n;j++)
            {
                if(nums[j]-nums[j-1]!=x)break;
                ans++;
            }
        }
        return ans;
        
    }
};