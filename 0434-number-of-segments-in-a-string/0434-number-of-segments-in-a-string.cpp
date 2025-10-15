class Solution {
public:
    int countSegments(string s) {

        int j=0;

        s+=" ";

        int cnt=0,cnt1=0;

        while(j<s.length())
        {
            if(s[j]==' ')
            {
                if(cnt1==0)
                {   j++;
                    continue;
                }
                cnt++;
                cnt1=0;
            }
            else cnt1++;
            j++;
        }
        return cnt;
        
    }
};