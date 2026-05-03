class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        vector<int> ans;
        ans.push_back(0);
        int odd=0,even=0;

        int n=nums.size();
        if(nums[n-1]%2==0)even++;
        else odd++;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]%2==0)ans.push_back(odd);
            else
            ans.push_back(even);

            if(nums[i]%2==0)even++;
            else odd++;
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};