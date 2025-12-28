class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long c1=1ll*cost1*need1;

        long long c2=1ll*cost2*need2;

        long long c3=1ll*costBoth*(max(need1,need2));

        long long c4=1ll*cost1*max(0,(need1-need2));

        long long c5=1ll*cost2*max(0,(need2-need1));

        long long c6=1ll*costBoth*need1;

        long long c7=1ll*costBoth*need2;

        long long ans=LLONG_MAX;

        ans=min(ans,c1+c2);
        ans=min(ans,c3);
        ans=min(ans,c4+c7);
        ans=min(ans,c5+c6);

        return ans;
        
    }
};