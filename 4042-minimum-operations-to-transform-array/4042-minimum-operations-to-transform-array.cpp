class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {

        long long ans=0;

        int n1=nums1.size();
        int n2=nums2.size();

        int mini=INT_MAX;

        for(int i=0;i<n1;i++)
        {
            if(nums2[n2-1]<=nums2[i] && nums2[n2-1]>=nums1[i]) mini=1;
            else if(nums2[n2-1]>=nums2[i] && nums2[n2-1]<=nums1[i])mini=1;
            else{
    mini=min(mini,min(abs(nums2[n2-1]-nums1[i])+1 , abs(nums2[n2-1]-nums2[i])+1));
            }
        }

        for(int i=0;i<n1;i++)
        {
            ans+=abs(nums1[i]-nums2[i]);
        }
        ans+=mini;

        return ans;
        
    }
};