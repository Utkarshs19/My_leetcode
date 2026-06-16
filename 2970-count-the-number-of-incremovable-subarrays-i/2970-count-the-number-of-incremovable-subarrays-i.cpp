class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {

        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                bool flag1=true,flag2=true;
                for(int k=1;k<i;k++)
                {
                    if(nums[k]<=nums[k-1]){
                        flag1=false;
                        break;
                    }
                }
                for(int k=j+2;k<nums.size();k++)
                {
                    if(nums[k-1]>=nums[k]){
                        flag2=false;
                        break;
                    }
                }

                if(i-1>=0 && j+1<nums.size() && nums[i-1]>=nums[j+1])
                {
                    flag1=false;
                    flag2=false;
                }

                if(flag1 && flag2){
                    ans++;
                    }
            }
        }

        return ans;
        
    }
};