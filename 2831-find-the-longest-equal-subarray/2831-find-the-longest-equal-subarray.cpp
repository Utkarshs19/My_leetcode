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

            while(j-i+1 - maxi >k)
            {
                m[nums[i]]--;
                i++;
            }

            ans=max(ans,maxi);  
            j++;
        }

        ans=max(ans,maxi);

        return ans;
        
    }
};