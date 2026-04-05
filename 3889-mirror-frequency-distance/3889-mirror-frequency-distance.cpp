class Solution {
public:
    int mirrorFrequency(string s) {

        vector<int> v1(10,0),v2(26,0);

        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                v1[s[i]-'0']++;
            }
            else
            {
                v2[s[i]-'a']++;
            }
        }
        int ans=0;

        int i=0,j=9;
        while(i<j)
        {
            ans+=abs(v1[i]-v1[j]);
            i++;
            j--;
        }
        i=0,j=25;
        while(i<j)
        {
            ans+=abs(v2[i]-v2[j]);
            i++;
            j--;
        }

        return ans;
        
    }
};