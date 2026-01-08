class Solution {
public:
    vector<vector<int>> dp;
    vector<int> a;
    vector<int> b;
    int n,m;
    
    int helper(int i,int j)
    {
        if(i==n || j==m)return -1e8;

        if(dp[i][j]!=INT_MIN)return dp[i][j];

        int take=a[i]*b[j];

        int ans=max({take+helper(i+1,j+1),take,helper(i+1,j),helper(i,j+1)});

        return dp[i][j]=ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        a=nums1,b=nums2;

        dp.assign(n+1,vector<int>(m+1,INT_MIN));

        return helper(0,0);

        
    }
};