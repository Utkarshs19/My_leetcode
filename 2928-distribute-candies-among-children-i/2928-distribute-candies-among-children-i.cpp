class Solution {
public:
    int distributeCandies(int n, int limit) {

        int ans=0;

        for(int i=0;i<=limit;i++)
        {
            for(int j=0;j<=limit;j++)
            {
                int x=n-i-j;
                if(x>=0 && x<=limit)ans++;
            }
        }

        return ans;
        
    }
};