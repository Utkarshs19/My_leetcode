class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        map<int,vector<int>> m;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }


        int ans=INT_MAX;

        for(auto i:m)
        {
            if(i.second.size()>=3)
            {
                vector<int> v=i.second;

                for(int j=2;j<v.size();j++)
                {
                    ans=min(ans,(abs(v[j]-v[j-2])+abs(v[j]-v[j-1])+abs(v[j-1]-v[j-2])));
                }
            }
        }
        

        return ans==INT_MAX?-1:ans;
    }
};