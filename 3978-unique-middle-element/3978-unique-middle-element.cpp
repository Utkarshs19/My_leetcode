class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {

        int num=nums[nums.size()/2];

        int cnt=0;
        for(auto i:nums)
        {
            if(i==num)cnt++;
        }
        return cnt==1;
        
    }
};