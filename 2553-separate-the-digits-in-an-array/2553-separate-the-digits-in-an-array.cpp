class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            vector<int> v;
            while(nums[i]>0)
            {
                v.push_back(nums[i]%10);
                nums[i]=nums[i]/10;
            }
            reverse(v.begin(),v.end());
            for(int j=0;j<v.size();j++)
            ans.push_back(v[j]);
        }
        return ans;
        
    }
};