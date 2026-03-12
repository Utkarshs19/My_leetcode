class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {

        int maxi=0;
        int ans=0;
        map<int,int> m;

        int i=0,j=0;

        while(j<nums.size())
        {
            m[nums[j]]++;
            maxi=max(maxi,m[nums[j]]);

            if(m.size()>1)
            {
                int x=j-i+1-maxi;
                ans=max(ans,maxi);

                if(x>k)
                {
                    m[nums[i]]--;
                    maxi=max(maxi,m[nums[i]]);
                    if(m[nums[i]]==0)m.erase(nums[i]);
                    i++;
                }
            }
            j++;
        }

        ans=max(ans,maxi);

        return ans;
        
    }
};