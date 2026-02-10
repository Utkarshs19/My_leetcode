class Solution {
public:
    string longestPalindrome(string s) {
        
        int idx,len=0;

        for(int i=0;i<s.length();i++)
        {
            int l=i,r=i;
            
            while(l>=0 && r<s.length() && s[l]==s[r])
            {
                if(r-l+1>len)
                {
                    len=r-l+1;
                    idx=l;
                }
                l--;
                r++;
            }

            l=i,r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r])
            {
                if(r-l+1>len)
                {
                    len=r-l+1;
                    idx=l;
                }
                l--;
                r++;
            }
        }

        return s.substr(idx,len);

    }
};