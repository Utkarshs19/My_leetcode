class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int ans=0;
        int i=0,j=0;

        while(i<nums1.size() && j<nums2.size())
        {
            if(nums2[j]>=nums1[i])
            {
                ans=max(ans,j-i);
                j++;
            }
            else
            {
                i++;
                if(j<i) j=i;   
            }
        }
        return ans;
    }
};