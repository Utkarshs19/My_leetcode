class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        map<int,int> m;

        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]]=i;
        }

        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};