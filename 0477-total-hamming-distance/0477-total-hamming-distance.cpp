class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        int n=nums.size();
        int ans=0;

        for(int i=0;i<32;i++)
        {
            int cnt=0;
            for(auto j:nums)
            {
                if(j &(1<<i))cnt++;
            }
            ans+=(cnt*(n-cnt));
        }

        return ans;
        
    }
};