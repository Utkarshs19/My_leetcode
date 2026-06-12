class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {

        int ans=0;
        sort(nums.begin(),nums.end());
        if(nums.size()<3)return 0;

        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]+nums[i+1]+nums[i+2]>=target)break;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                while(j<k && nums[i]+nums[j]+nums[k]>=target)k--;
                ans+=(k-j);
                j++;
            }
        }

        return ans;
        
    }
};