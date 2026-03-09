class Solution {
public:
    int ans=0;
    void helper(int i,int n,int limit)
    {
        if(i==3)
        {
            if(n==0)ans++;

            return;
        }

        for(int j=0;j<=limit;j++)
        {
            helper(i+1,n-j,limit);
        }
    }

    int distributeCandies(int n, int limit) {
        
        helper(0,n,limit);

        return ans;

    }
};