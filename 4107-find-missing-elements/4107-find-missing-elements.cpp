class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int maxi=*max_element(nums.begin(),nums.end());

        int mini=*min_element(nums.begin(),nums.end());
        
        set<int> s;
        for(int i=mini;i<=maxi;i++)
        s.insert(i);

        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
            s.erase(nums[i]);
        }

        vector<int> ans;
        for(auto i:s)
        ans.push_back(i);

        return ans;
        
    }
};