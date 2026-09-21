class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k,0); 
        vector<long long> prev(k,0);

        for(int i=0;i<nums.size();i++)
        {
            vector<long long> cur(k,0);
            cur[nums[i]%k]++;

            for(int j=0;j<k;j++)
            {
                long long x=(1ll * j*(nums[i]%k))%k;
                
                cur[x]+=prev[j];
            }

            for(int j=0;j<k;j++)
            {
                ans[j]+=cur[j];
            }
            prev=cur;
        }

        return ans;
        
    }
};