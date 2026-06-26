class Solution {
public:
    int longestSubstring(string s, int k) {

        int ans=0;
        map<char,int> m;

        for(int i=0;i<s.length();i++)
        {
           m[s[i]]++;
           int flag=0;
           for(auto i:m)
           {
               if(i.second<k)
               flag=-1;
           }
           if(flag==0)
           ans=max(ans,i+1);
        }

        return ans;
        
    }
};