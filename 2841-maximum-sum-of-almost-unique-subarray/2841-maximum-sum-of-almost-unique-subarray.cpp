class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {

        map<int,int> m1;
        long long ans=0;
        long long sum=0;

        int i=0,j=0;

        while(j<nums.size())
        {
            m1[nums[j]]++;
            sum+=nums[j];

            if(j-i+1==k)
            {
                if(m1.size()>=m)
                {
                    ans=max(ans,sum);
                }

                m1[nums[i]]--;
                if(m1[nums[i]]==0)m1.erase(nums[i]);
                sum=sum-nums[i];
                i++;
            }
            j++;
        }
        
        return ans;
    }
};