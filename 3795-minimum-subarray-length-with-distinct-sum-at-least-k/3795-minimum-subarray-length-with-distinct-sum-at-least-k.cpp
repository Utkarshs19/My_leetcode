class Solution {
public:
    int minLength(vector<int>& nums, int k) {

        int i=0,j=0;
        int sum=0;
        map<int,int> m;

        int ans=INT_MAX;

        while(j<nums.size())
        {
            if(m[nums[j]]==0)
            {
                sum+=nums[j];
            }
            m[nums[j]]++;

            while(i<=j && sum>=k)
            {
                ans=min(ans,j-i+1);

                m[nums[i]]--;
                if(m[nums[i]]==0)
                sum=sum-nums[i];

                i++;
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};