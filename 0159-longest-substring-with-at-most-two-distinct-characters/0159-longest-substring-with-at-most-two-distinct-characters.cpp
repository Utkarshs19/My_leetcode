class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {

        map<char,int> m;

        int i=0,j=0;

        int ans=0;

        while(j<s.length())
        {
            m[s[j]]++;

            while(m.size()>2)
            {
                m[s[i]]--;
                if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};