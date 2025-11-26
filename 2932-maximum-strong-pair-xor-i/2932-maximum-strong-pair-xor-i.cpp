class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {

        int ans=-1;

        for(int i=0;i<nums.size();i++)
        {   
            int x=nums[i];
            for(int j=0;j<nums.size();j++)
            {
                int y=nums[j];

                if(abs(x-y)<=min(x,y))
                {
                    ans=max(ans,x^y);
                }
            }
        }

        return ans;
        
    }
};