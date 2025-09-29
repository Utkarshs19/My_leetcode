class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        map<int,int> m,left,right;
        int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;

            if(left.find(nums[i])==left.end())
            {
                left[nums[i]]=i;
            }
            right[nums[i]]=i;

            maxi=max(maxi,m[nums[i]]);
        }

        int ans=1e9;


        for(auto i:m)
        {
            if(i.second==maxi)
            {
                ans=min(ans,right[i.first]-left[i.first]+1);
            }
        }

        return ans;

        
        
    }
};