class Solution {
public:
    int maximumSum(vector<int>& nums) {

        int n=nums.size();

        map<int,vector<int>> m;

        for(int i=0;i<n;i++)
        {
            m[nums[i]%3].push_back(nums[i]);
        }
        int ans=0;
        vector<int> v1=m[0],v2=m[1],v3=m[2];

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());

        if(v1.size()>=3)
        ans=max(ans,v1[v1.size()-1]+v1[v1.size()-2]+v1[v1.size()-3]);

        if(v2.size()>=3)
        ans=max(ans,v2[v2.size()-1]+v2[v2.size()-2]+v2[v2.size()-3]);

        if(v3.size()>=3)
        ans=max(ans,v3[v3.size()-1]+v3[v3.size()-2]+v3[v3.size()-3]);

        if(v1.size()>=1 && v2.size()>=1 && v3.size()>=1)
        ans=max(ans,v1[v1.size()-1]+v2[v2.size()-1]+v3[v3.size()-1]);

        return ans;
        
    }
};