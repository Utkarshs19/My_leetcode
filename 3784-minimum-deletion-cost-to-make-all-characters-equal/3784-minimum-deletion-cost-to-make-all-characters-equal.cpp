class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

        long long sum=accumulate(cost.begin(),cost.end(),0LL);

        long long ans=LLONG_MAX;

        map<char,vector<int>> m;

        for(int i=0;i<s.length();i++)
        {
            m[s[i]].push_back(cost[i]);
        }

        for(auto i:m)
        {
            vector<int> v=i.second;
            long long x=accumulate(v.begin(),v.end(),0LL);

            ans=min(ans,sum-x);
        }

        return ans;
        
    }
};