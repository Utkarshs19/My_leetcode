class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {

        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            set<int> st;
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                st.insert(nums[j]);
                sum+=nums[j];

                if(st.count(sum))
                ans++;
            }
        }

        return ans;
        
    }
};