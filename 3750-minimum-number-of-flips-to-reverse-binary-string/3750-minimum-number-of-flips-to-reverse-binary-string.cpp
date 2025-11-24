class Solution {
public:
    int minimumFlips(int n) {

        string str="";

        while(n>0)
        {
            str+=(to_string(n%2));
            n=n/2;
        }

        string s=str;
        reverse(str.begin(),str.end());

        if(s==str)return 0;

        int i=0;
        int ans=0;
        while(i<s.length())
        {
            if(s[i]!=str[i])ans++;
            i++;
        }

        return ans;
        
    }
};