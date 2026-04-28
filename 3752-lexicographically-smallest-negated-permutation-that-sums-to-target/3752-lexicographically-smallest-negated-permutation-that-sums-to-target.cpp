class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {

        long long sum=(1ll*n*(n+1))/2;

        if(target>sum || target<-sum || (sum-target)%2==1)return {};

      

        vector<int> v;
        for(int i=n;i>=1;i--)
        v.push_back(i);

        long long rem=sum-target;

        for(int i=0;i<n;i++)
        {
           int x=v[i];

            if(2*x<=rem)
            {
                v[i]=-1*v[i];
                rem=rem-2*x;
            }
        }   

        sort(v.begin(),v.end());

        return v;

        
    }
};