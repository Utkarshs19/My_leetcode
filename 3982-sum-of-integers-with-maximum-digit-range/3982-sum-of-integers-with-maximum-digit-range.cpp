class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        int ans=0;

        map<int,int> m;
        int y=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int maxi=0,mini=1e9;
            while(x>0)
            {
                maxi=max(maxi,x%10);
                mini=min(mini,x%10);
                x=x/10;
            }
            y=max(y,maxi-mini);
            m[nums[i]]=maxi-mini;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==y)ans+=nums[i];
        }
        return ans;
        
    }
};