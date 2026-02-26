class Solution {
public:

    string odd(string s)
    {
        int i=s.length()-1;
        bool flag=false;
        while(i>=0 && s[i]=='1')
        {
            s[i]='0';
            i--;
        }
        if(i>=0)s[i]='1';
        else
        s='1'+s;

        return s;
    }

    string even(string s)
    {
        s.pop_back();
        return s;
    }

    int numSteps(string s) {
        int ans=0;
        while(s!="1")
        {
            ans++;
            if(s[s.length()-1]=='1')
            {
                s=odd(s);
            }
            else
            {
                s=even(s);
            }
        }

        return ans;
        
    }
};