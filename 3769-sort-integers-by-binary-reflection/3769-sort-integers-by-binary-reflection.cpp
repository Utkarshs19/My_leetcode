class Solution {
public:

    int binary(int n)
    {
        vector<int> v;
        int x=0;
        while(n>0)
        {
            x=x*2+n%2;
            n=n/2;
        }

        return x;
    }

    vector<int> sortByReflection(vector<int>& nums) {

        map<int,vector<int>> m;

        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            int x=binary(nums[i]);
            m[x].push_back(nums[i]);
        }

        for(auto i:m)
        {
            vector<int> v=i.second;
            sort(v.begin(),v.end());
            for(int j=0;j<v.size();j++)
            {
                ans.push_back(v[j]);
            }
        }
        
        return ans;
    }
};