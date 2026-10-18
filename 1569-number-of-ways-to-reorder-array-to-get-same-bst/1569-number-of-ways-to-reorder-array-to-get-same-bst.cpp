class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    vector<vector<ll>> v;
    int n;
   
    int helper(vector<int> &nums)
    {
        int n=nums.size();
        if(n<=2)return 1;

        int root=nums[0];
        vector<int> left,right;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<root)left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        ll x=helper(left);
        ll y=helper(right);
        ll a=(x*y)%mod;
        
        ll z=v[n-1][left.size()];

        return (z*a)%mod;
    }
    int numOfWays(vector<int>& nums) {
        
        this->n=nums.size();
        
        v.resize(n+1);

        for(int i=0;i<=n;i++)
        {
            v[i]=vector<ll>(i+1,1);

            for(int j=1;j<i;j++)
            {
                v[i][j]=(v[i-1][j]+v[i-1][j-1])%mod;
            }
        }

        return (helper(nums)+mod)%mod-1;

    }
};