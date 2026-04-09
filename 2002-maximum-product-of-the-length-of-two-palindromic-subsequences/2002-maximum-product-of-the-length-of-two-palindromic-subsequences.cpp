class Solution {
public:
    int ans=0;

    bool isPal(string s)
    {
        int i=0,j=s.length()-1;

        while(i<=j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    void helper(int i,string &s,string s1,string s2)
    {
        if(i==s.length())
        {
            if(isPal(s1) && isPal(s2))
            {
                ans=max(ans,(int)(s1.length()*s2.length()));
            }
            return;
        }

        s1+=s[i];
        helper(i+1,s,s1,s2);
        s1.pop_back();

        s2+=s[i];
        helper(i+1,s,s1,s2);
        s2.pop_back();

        helper(i+1,s,s1,s2);
    }

    int maxProduct(string s) {

        helper(0,s,"","");

        return ans;
        
    }
};