class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<int> v=nums;

        int i=0,j=0;
        int n=nums.size();
        while(i<n && j<n)
        {
            if(nums[i]<v[j])
            {
                i++;j++;
            }
            else
            {
                j++;
            }
        }

        return i;
        
    }
};