class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        vector<int> result(nums.size());
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            result[i]=nums[(i+ nums[i]%n + n)%n];
        }

        return result;
        
    }
};