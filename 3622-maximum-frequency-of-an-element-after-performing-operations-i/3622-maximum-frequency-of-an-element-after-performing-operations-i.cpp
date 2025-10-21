class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int maxi=*max_element(nums.begin(),nums.end());

        vector<int> f(maxi+k+5 ,0);

        for(auto i:nums)
        {
            f[i]++;
        }

        for(int i=1;i<f.size();i++)
        {
            f[i]+=f[i-1];
        }

        int ans=0;

        for(int i=0;i<f.size();i++)
        {
            int left=max(0,i-k);
            int right=min(int(f.size()-1),i+k);

            int total=f[right]-(left?f[left-1]:0);
            int freq=f[i]-(i?f[i-1]:0);

            ans=max(ans,freq+min(numOperations,total-freq));
        }

        return ans;
        
    }
};