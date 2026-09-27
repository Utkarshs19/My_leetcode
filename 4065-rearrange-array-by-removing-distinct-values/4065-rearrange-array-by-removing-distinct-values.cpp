class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans;
        
        vector<int> v(101,0);
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]++;
        }

        int sum=accumulate(v.begin(),v.end(), 0);
        while(sum>0)
        {
            for(int i=0;i<v.size();i++)
            {
                if(v[i]>0)
                {
                ans.push_back(i);
                sum--;
                v[i]--;
                }
            }
        }

        return ans;
    }
};