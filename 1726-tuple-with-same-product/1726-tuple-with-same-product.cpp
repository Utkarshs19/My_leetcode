class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        map<int,int> m;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                m[nums[i]*nums[j]]++;
            }
        }

        int ans=0;

        for(auto i:m)
        {
            if(i.second>1)
            {
                int x=(i.second * (i.second-1))/2;

                ans+=(x*8);
                
            }
        }

        return ans;
        
    }
};