class Solution {
public:
    int countBinarySubstrings(string s) {

        vector<int> v;
        int cnt=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i-1]==s[i])cnt++;
            else
            {
                v.push_back(cnt+1);
                cnt=0;
            }
        }
        v.push_back(cnt+1);

        int ans=0;
        for(int i=1;i<v.size();i++)
        {
            ans=ans+min(v[i],v[i-1]);
        }

        return ans;
        
    }
};