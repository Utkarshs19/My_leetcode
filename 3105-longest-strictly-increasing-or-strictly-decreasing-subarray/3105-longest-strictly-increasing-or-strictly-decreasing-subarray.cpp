class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
    int maxi=1;
    int mini=1;

    int cnt1=1;
    int cnt2=1;
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]<nums[i+1])
        {
            cnt1++;
            cnt2=1;
            maxi=max(maxi,cnt1);
        }
        else if(nums[i]>nums[i+1])
        {
            cnt1=1;
            cnt2++;
            mini=max(mini,cnt2);
        }
        else
        {
            cnt1=1;
            cnt2=1;
        }
    }
    return max(maxi,mini);
    }
};