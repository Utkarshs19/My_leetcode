class Solution {
public:

    bool helper(string str)
    {
        int n=str.length();
        int i=0,j=n-1;

        while(i<j)
        {
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {


        int ans=0;
       
        for(int i=0;i<s.length();i++)
        {
            string str;
            for(int j=i;j<s.length();j++)
            {
                str+=s[j];
                if(helper(str))
                ans=max(ans,j-i+1);

                for(int a=0;a<t.length();a++)
                {
                    string t1;
                    for(int b=a;b<t.length();b++)
                    {
                        t1+=t[b];
                        if(helper(t1))
                        ans=max(ans,b-a+1);

                        if(helper(str+t1))
                        ans=max(ans,(int)(str.length()+t1.length()));
                    }
                }
            }

        }

        return ans;
        
    }
};