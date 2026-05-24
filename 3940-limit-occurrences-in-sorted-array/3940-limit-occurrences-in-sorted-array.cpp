class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        map<int,int> m;

        for(auto i:nums)
        {
            m[i]++;
        }

        for(auto i:m)
        {
            if(i.second>=k)
            m[i.first]=k;
        }

        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i])){
            ans.push_back(nums[i]);
            m[nums[i]]--;
            if(m[nums[i]]==0)m.erase(nums[i]);
            }

        }
        return ans;
        
    }
};