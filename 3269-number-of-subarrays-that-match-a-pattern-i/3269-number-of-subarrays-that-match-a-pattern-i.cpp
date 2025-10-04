class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        int ans=0;

        for(int i=pattern.size();i<nums.size();i++)
        {
            int j=i;
            int cnt=0;
            int k=pattern.size();
            while(k>0)
            {
                if(nums[j]>nums[j-1] &&  pattern[k-1]==1)cnt++;
                if(nums[j]==nums[j-1] && pattern[k-1]==0)cnt++;
                if(nums[j]<nums[j-1] && pattern[k-1]==-1)cnt++;

                k--;
                j--;
            }
            if(cnt==pattern.size())ans++;
        }

        return ans;
    }
};