class Solution {
public:
    bool hasMatch(string s, string p) {

        string p1,p2;
        int i=0;
        for(i=0;i<p.length();i++)
        {
            if(p[i]=='*')break;
            else
            p1+=p[i];
        }
        i++;
        for(i;i<p.length();i++)
        {
            p2+=p[i];
        }

        if(p1=="")
        {
            int i=0,j=0;
            int k=0;
            while(i<s.length() && j<p2.length())
            {
                if(s[i]==p2[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    k++;
                    i=k;
                    j=0;
                }
            }

            return j==p2.length();
        }
        else if(p2=="")
        {
             int i=0,j=0;
             int k=0;
            while(i<s.length() && j<p1.length())
            {
                if(s[i]==p1[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    k++;
                    i=k;
                    j=0;
                }
            }

            return j==p1.length();
        }
        else
        {
            int i=0,j=0;
            int a=0;
            while(i<s.length()&& j<p1.length())
            {
                if(s[i]==p1[j])
                {
                    i++;j++;
                }
                else
                {   
                    a++;
                    i=a;;j=0;
                }
            }
            a=i;
            i=a;
            int k=0;
            while(i<s.length()&& k<p2.length())
            {
                if(s[i]==p2[k])
                {
                    i++;k++;
                }
                else
                {
                    a++;
                    i=a;
                    k=0;
                }
            }
            return j==p1.length()&&k==p2.length();
        }



        return true;
        
    }
};