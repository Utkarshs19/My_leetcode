class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int ans=0;

        int sum=0;

        map<int,int> m;

        int i=0,j=0;

        while(j<nums.size())
        {
            sum+=nums[j];
            m[nums[j]]++;
            if(j-i+1>m.size())
            {
                while(j-i+1 > m.size())
                {
                    sum=sum-nums[i];
                    m[nums[i]]--;
                    if(m[nums[i]]==0)m.erase(nums[i]);
                    i++;
                }
            }
            ans=max(ans,sum);
            j++;
        }

        return ans;
        
    }
};