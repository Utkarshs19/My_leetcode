class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> m;

        int ans=0;
        int i=0,j=0;

        int maxi=0;

        while(j<s.length())
        {
            m[s[j]]++;
            maxi=max(maxi,m[s[j]]);

            while((j-i+1)-maxi>k)
            {
                m[s[i]]--;
                i++;
            }
            
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};