class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;
        if(nums.size()==0)return ans;
        int start=0;
        int i;
        for( i=1;i<nums.size();i++)
        {
            if(nums[i-1]+1==nums[i])continue;
            else
            {
                if(start==i-1)
                ans.push_back(to_string(nums[start]));
                else
                {
                    string s=to_string(nums[start]);
                    s+="->";
                    s+=to_string(nums[i-1]);
                    ans.push_back(s);
                }
                start=i;
            }
        }

        if(start==i-1)
            ans.push_back(to_string(nums[start]));
        else
            {
                string s=to_string(nums[start]);
                s+="->";
                s+=to_string(nums[i-1]);
                ans.push_back(s);
          }


        return ans;
        
    }
};