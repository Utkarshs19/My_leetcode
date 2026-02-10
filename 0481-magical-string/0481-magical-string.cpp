class Solution {
public:
    int magicalString(int n) {

        if(n==0)
        return 0;
        if(n<=3)return 1;

        string s="122";
        int i=2;
        bool flag=true;

        long long  ans=0;
        

        while(i<s.length())
        {
            
            if(flag)
            {
                if(s[i]=='2')
                {
                    s+="11";
                }
                else
                {
                    s+="1";
                }
            }
            else
            {
                if(s[i]=='2')
                {
                    s+="22";
                }
                else
                {
                    s+="2";
                }   
            }
            i++;
            flag=!flag;

            if(s.length()>=n)break;
        }        

        i=0;

        while(i<n)
        {
            if(s[i]=='1')ans++;
            i++;
        }

        return ans;

    }
};