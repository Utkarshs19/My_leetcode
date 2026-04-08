class Solution {
public:
    const int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];

            while(l<=r)
            {
                nums[l]=(1ll*nums[l]*v)%mod;
                l+=k;
            }
        }

        int xorr=0;

        for(int i=0;i<nums.size();i++)
        {
            xorr=xorr^nums[i];
        }

        return xorr;

    }
};