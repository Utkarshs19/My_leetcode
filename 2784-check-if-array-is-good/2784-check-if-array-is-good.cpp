class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n=nums.size();

        if(n==1)return false;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=i+1)return false;
        }
        if(nums[n-2]==n-1 && nums[n-1]==n-1)return true;
        return false;


    }
};