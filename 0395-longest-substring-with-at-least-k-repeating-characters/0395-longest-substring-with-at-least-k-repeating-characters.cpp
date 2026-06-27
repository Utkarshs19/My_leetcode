class Solution {
public:
    int longestSubstring(string s, int k) {

        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            map<char,int> m;
            for(int j=i;j<s.length();j++)
            {
                m[s[j]]++;
                int mini=INT_MAX;
                for(auto i:m)
                {
                    mini=min(mini,i.second);
                }
                if(mini>=k)
                {
                    ans=max(ans,(int)(j-i+1));
                }
            }
        }
        

        return ans;
    }
};