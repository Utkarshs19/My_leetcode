class Solution {
public:
    string addBinary(string a, string b) {

        string ans="";

        int i=a.length()-1,j=b.length()-1;
        int carry=0;

        while(i>=0 && j>=0)
        {
            if(a[i]=='1' && b[j]=='1')
            {
                if(carry==0)
                {
                    ans+='0';
                }
                else
                {
                    ans+='1';
                }
                carry=1;
            }
            else if(a[i]=='1' || b[j]=='1')
            {
                if(carry==1)
                {
                    ans+='0';
                    carry=1;
                }
                else
                {
                    ans+='1';
                }
            }
            else
            {
                if(carry==1)
                {
                    ans+='1';
                    carry=0;
                }
                else
                {
                    ans+='0';
                }
            }
            i--;
            j--;
        }
        while(j>=0)
        {
            if(b[j]=='1' && carry==1)
            {
                ans+='0';
                carry=1;
            }
            else if(b[j]=='1' && carry==0)
            {
                ans+='1';
                carry=0;
            }
            else if(b[j]=='0' && carry==1)
            {
                ans+='1';
                carry=0;
            }
            else
            {
                ans+='0';
                carry=0;
            }
            j--;
        }

        while(i>=0)
        {
            if(a[i]=='1' && carry==1)
            {
                cout<<"heloo";
                ans+='0';
                carry=1;
            }
            else if(a[i]=='1' && carry==0)
            {
                ans+='1';
                carry=0;
            }
            else if(a[i]=='0' && carry==1)
            {
                ans+='1';
                carry=0;
            }
            else
            {
                ans+='0';
                carry=0;
            }
            i--;
        }

        if(carry)ans+='1';

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};