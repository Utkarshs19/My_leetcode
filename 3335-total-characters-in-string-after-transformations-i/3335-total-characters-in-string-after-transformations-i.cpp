class Solution {
public:
    const int mod=1000000007;
    int lengthAfterTransformations(string s, int t) {

        vector<int> cnt(26,0);
        for(auto i:s)
        {
            cnt[i-'a']++;
        }

        for(int i=0;i<t;i++)
        {
            vector<int> v(26);
            v[0]=cnt[25];
            v[1]=(cnt[25]+cnt[0])%mod;
            for(int j=2;j<26;j++)
            {
                v[j]=cnt[j-1];
            }
            cnt=v;
        }

        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans=(ans+cnt[i])%mod;
        }

        return ans;
        
    }
};