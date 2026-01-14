class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int ans=0;

        int sum=0;

        set<int> st;

        int i=0,j=0;

        while(j<nums.size())
        {
            while(st.count(nums[j]))
            {
                sum=sum-nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            st.insert(nums[j]);
            ans=max(ans,sum);
            j++;
        }

        return ans;
        
    }
};