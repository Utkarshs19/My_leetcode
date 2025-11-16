class Solution {
public:
    int minLengthAfterRemovals(string s) {

        int cnt1=0,cnt2=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')cnt1++;
            else cnt2++;
        }

        return abs(cnt1-cnt2);
        
    }
};