class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {

        map<int,int> m;

        for(auto i:nums)
        {
            if(i%2==0)
            {
                m[i]++;
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i]))
            {
                if(m[nums[i]]==1)return nums[i];
            }
        }
        return -1;
        
    }
};