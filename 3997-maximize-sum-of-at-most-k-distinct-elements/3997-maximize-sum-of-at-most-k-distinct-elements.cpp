class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {

        vector<int> ans;

        map<int,int> m;

        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        vector<int> v;

        for(auto i:m)
        {
            v.push_back(i.first);
        }

        reverse(v.begin(),v.end());

        for(int i=0;i<k&&i<v.size();i++)
        {
            ans.push_back(v[i]);
        }


        return ans;

        
    }
};