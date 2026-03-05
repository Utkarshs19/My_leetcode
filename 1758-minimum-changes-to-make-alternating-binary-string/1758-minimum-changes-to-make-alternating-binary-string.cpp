class Solution {
public:
    int minOperations(string s) {
        int n=s.length();

        string s1="1",s2="0";

        for(int i=1;i<n;i++)
        {
            if(s1[i-1]=='1')s1+="0";
            else s1+="1";
        }

        for(int i=1;i<n;i++)
        {
            if(s2[i-1]=='1')s2+="0";
            else s2+="1";
        }

        int ans1=0,ans2=0;

        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s[i])ans1++;
            if(s2[i]!=s[i])ans2++;
        }

        return min(ans1,ans2);
    }
};