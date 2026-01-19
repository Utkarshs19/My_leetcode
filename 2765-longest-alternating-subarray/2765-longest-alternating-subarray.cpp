class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {

        int ans=-1;

        for(int i=0;i<nums.size();i++)
        {
            bool flag=true;
            int j;
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[j]-nums[j-1]==1 && flag==true)
                {
                    flag=false;
                }
                else if(nums[j]-nums[j-1]==-1 && flag==false)
                {
                    flag=true;
                }
                else
                break;
            }
            ans=max(ans,j-i);
        }

        return ans<=1?-1:ans;
        
    }
};