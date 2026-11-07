class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        
        int ans=INT_MAX;

        for(int i=0;i<nums.size();i+=2)
        {
            int x=nums[i];
            string str=to_string(nums[i+1]);
            int j=0;
            while(j<str.length())
            {
                x=x*10+(str[j]-'0');
                j++;
            }
            ans=min(ans,x);
        }
        return ans;
    }
};