class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        long long sum=accumulate(nums.begin(),nums.end(),0);
        
        long long target=sum-x;
        if(target<0)return -1;
        if(target==0)return nums.size();
        int i=0,j=0;
        int len=0;
        long long cur=0;
        while(j<nums.size())
        {
            cur+=nums[j];

            while(i<=j && cur>target)
            {
                cur=cur-nums[i];
                i++;
            }
            if(cur==target)
            {
                len=max(len,j-i+1);
            }
            j++;
        }
        
        if(len==0)return -1;
        return nums.size()-len;
    }
};