class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int cur=0;
        int maxi=0;

        int i=0,j=0;

        while(j<s.length())
        {
            cur+=abs(t[j]-s[j]);

            while(i<s.length()&&cur>maxCost)
            {
                cur=cur-abs(t[i]-s[i]);
                i++;
            }

            maxi=max(maxi,(j-i+1));
            j++;
        }

        return maxi;
        
    }
};