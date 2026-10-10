class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int k=k1+k2;

        vector<int> v(100001,0);

        for(int i=0;i<nums1.size();i++)
        {
            v[abs(nums1[i]-nums2[i])]++;
        }
        
        for(int i=v.size()-1;i>0 && k>0;i--)
        {
            int ops=min(v[i],k);
            v[i]-=ops;
            v[i-1]+=ops;
            k=k-ops;
        }

        long long ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans+=(1ll*i*i*v[i]);
        }
        return ans;
    }
};