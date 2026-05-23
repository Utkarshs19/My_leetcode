class Solution {
public:
    bool check(vector<int>& nums) {
        
        int mini =INT_MAX;

        vector<int> v=nums;
        sort(v.begin(),v.end());

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
            
            if(v==nums)return true;
        }

        return false;

    }
};