class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {

        map<int,vector<int>> m;

        int ans=1e9;

        for(int i=0;i<nums1.size();i++)
        {
            m[nums1[i]].push_back(i);
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(m.count(nums2[i]))
            {
                vector<int> v=m[nums2[i]];

                for(int j=0;j<v.size();j++)
                {
                    ans=min(ans,i+v[j]);
                    if(ans==0)return ans;
                }
            }
        }

        return ans==1e9?-1:ans;
        
    }
};