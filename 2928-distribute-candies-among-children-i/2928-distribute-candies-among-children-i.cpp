class Solution {
public:
    int ans=0;
    vector<int> v;
    void helper(int i,int n,int limit)
    {
        if(i==3)
        {
            if(accumulate(v.begin(),v.end(),0)==n)ans++;

            return;
        }

        for(int j=0;j<=limit;j++)
        {
            v[i]=j;
            helper(i+1,n,limit);
        }
    }

    int distributeCandies(int n, int limit) {
        
        v.resize(3,0);
        helper(0,n,limit);

        return ans;

    }
};