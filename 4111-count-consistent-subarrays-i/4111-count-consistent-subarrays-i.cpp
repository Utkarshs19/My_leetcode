class Solution {
public:
    int countConsistent(vector<int>& nums) {

        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            int mini=nums[i];
            int b=nums[i];
            for(int j=i;j<nums.size();j++)
            {
                mini=min(mini,nums[j]);
                b=b&nums[j];

                if(b==mini)ans++;
            }
        }
        return ans;
        
    }
};