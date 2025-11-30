class Solution {
public:
    int countElements(vector<int>& nums, int k) {

        map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        int n=nums.size();
        int ans=0;
        int cnt=0;

        for(auto i:m)
        {
            if(n-cnt-i.second>=k)ans+=i.second;
            cnt+=i.second;
        }
        return ans;
        
    }
};