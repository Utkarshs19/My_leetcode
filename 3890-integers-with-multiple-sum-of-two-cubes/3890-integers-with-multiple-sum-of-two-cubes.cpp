class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        map<int,int> m;

        for(int i=1;1ll*i*i*i<=n;i++)        
        {
            long long x=1ll*i*i*i;
            for(int j=i+1;x+1ll*j*j*j<=n;j++) 
            {
                long long sum=x+1ll*j*j*j;
                m[sum]++;
            }
        }

        vector<int> ans;

        for(auto i:m)
        {
            if(i.second>=2)
            ans.push_back(i.first);
        }
        return ans;
    }
};