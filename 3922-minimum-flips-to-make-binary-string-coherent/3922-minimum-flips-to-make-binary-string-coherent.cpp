class Solution {
public:
    int minFlips(string s) {
        
        if(s.length()<3)return 0;
        int cnt1=0 ,cnt2=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')cnt1++;
            else cnt2++;
        }
     

        int cnt3=cnt1-(s[0]-'0')-(s[s.length()-1]-'0');

        return min({cnt2,max(0,cnt1-1),cnt3});

        
    }
};