class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int i=0,j=0;
        int n=nums.size();

        multiset<int> st;

        long long ans=0;

        while(j<n)
        {
            st.insert(nums[j]);

            long long mini=*st.begin();
            long long maxi=*st.rbegin();
            int size=st.size();
            long long val=(maxi-mini)*size;
            while(val>k)
            {
                st.erase(st.find(nums[i++]));
                val=(*st.rbegin()-*st.begin())*st.size();
            }
            ans+=st.size();
            j++;
        }
        return ans;
    }
};