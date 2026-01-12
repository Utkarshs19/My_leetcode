class Solution {
public:
    map<int,int> m;

    int helper(int i,string s)
    {
        if(i==s.length())return 1;

        if(m.count(i))return m[i];

        if(s[i]=='0')return 0;

        int x=helper(i+1,s);
        if(i+1<s.length() && (s[i]=='1' || (s[i]=='2'&&s[i+1]<'7') ))
        x+=helper(i+2,s);

        return m[i]=x;
    }

    int numDecodings(string s) {
        
        return helper(0,s);
    }
};