class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxi=0;
        int i=0,j=0;
        int cnt=0;

        while(j<nums.size())
        {
            
            if(nums[j]==0)cnt++;
 
            if(cnt==2)
            {
                
                while(cnt!=1)
                {
                    if(nums[i]==0)cnt--;
                    i++;
                }
            }
            maxi=max(maxi,j-i);
             j++;

        }
       
        return maxi;   
    }
};