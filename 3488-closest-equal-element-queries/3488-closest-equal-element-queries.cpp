class Solution {
public:

    int helper(int idx,vector<int> &v,int n)
    {
        int low=0,high=v.size()-1;
        int tar;
        if(v.size()==1)return -1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(v[mid]==idx)
            {
                tar=mid;
                break;
            }
            else if(v[mid]>idx)
            {
                high=mid-1;
            }
            else
            low=mid+1;
        }
        int ans=1e9;
        if(tar-1>=0)
        ans=min(ans,v[tar]-v[tar-1]);
        if(tar+1<v.size())
        ans=min(ans,v[tar+1]-v[tar]);

        if(tar==0 || tar==(int)(v.size()-1))
            ans=min(ans, n-v[v.size()-1]+v[0]);  

        
        return ans;

    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        vector<int> ans;

        map<int,vector<int>> m;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }

        for(int i=0;i<queries.size();i++)
        {
            vector<int>& v=m[nums[queries[i]]];
            ans.push_back(helper(queries[i],v,nums.size()));
        }

        return ans;
        
        
        
    }
};