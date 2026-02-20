class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(nums.size()==1)
        {
            if(k%2==1)
            return -1;
            else
            return nums[0];
        }

        if(k==0)return nums[0];

        if(k==1)return nums[1];

         int maxi = 0;
        
        for(int i = 0; i < min(n, k-1); i++)
            maxi = max(maxi, nums[i]);
        
        if(k < n)
            maxi = max(maxi, nums[k]);
        
        return maxi;


    }
};