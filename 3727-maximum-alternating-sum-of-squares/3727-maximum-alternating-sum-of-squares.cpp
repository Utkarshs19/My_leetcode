class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        vector<int> v;

        for(auto i:nums)
        {
            v.push_back(i*i);
        }

        sort(v.begin(),v.end());

        

        long long ans=0;

        for(int i=0,j=v.size()-1;i<j;i++,j--)
        {
            ans+=v[j];
            ans-=v[i];
        }

        if(v.size()%2==1)
        ans+=v[v.size()/2];

        return ans;
        
    }
};