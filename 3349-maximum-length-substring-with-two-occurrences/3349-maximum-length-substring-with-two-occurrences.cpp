class Solution {
public:
    int maximumLengthSubstring(string s) {

        int maxi=0;

        for(int i=0;i<s.length();i++)
        {
            map<char,int> m;

            for(int j=i;j<s.length();j++)
            {
                m[s[j]]++;
                if(m[s[j]]>2)
                break;

                maxi=max(maxi,j-i+1);
            }

        }

        return maxi;
        
    }
};