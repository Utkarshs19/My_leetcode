class Solution {
public:
    bool checkOnesSegment(string s) {

        if(s.length()==1 &&s[0]=='1')return true;

        int i=0;
        int cnt=0;
        int x=0;
        
        while(i<s.length())
        {
            if(s[i]=='1')cnt++;
            else
            {
                if(cnt>=1)
                x++;
                
                cnt=0;
            }
            i++;
        }

        if(cnt>=1)x++;

     

        return x==1;
    }
};