class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {

        map<long long, long long> m;

        for(auto i:power)
        {
            m[i]++;
        }

        unordered_map<long long ,long long> dp;

        long long ans=0,backEl=0,prevEl;

        for(auto i:m)
        {
            auto backIt=m.lower_bound(i.first-2);
            if(backIt!=m.begin())
            backEl=(*(--backIt)).first;

            dp[i.first]=max(dp[prevEl],(i.first*i.second)+dp[backEl]);

            ans=max(ans,dp[i.first]);

            prevEl=i.first;

        }
        
        return ans;
    }
};