class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {

        map<int,int> m;

        int ans=1e9;

        for(int i=0;i<nums1.size();i++)
        {
            if(!m.count(nums1[i]))
            {
                m[nums1[i]]=i;
            }
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(m.count(nums2[i]))
            {
                ans=min(ans,i+m[nums2[i]]);
            }
        }

        return ans==1e9?-1:ans;
        
    }
};