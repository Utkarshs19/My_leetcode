class Solution {
public:
    long long numberOfSubstrings(string s) {

        map<int,int> m;

        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }

        long long ans=s.length();

        for(auto i:m)
        {
            ans+=(1ll*i.second*(i.second-1))/2;
        }

        return ans;
        
    }
};