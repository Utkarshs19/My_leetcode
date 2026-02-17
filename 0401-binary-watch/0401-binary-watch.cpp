class Solution {
public:
    vector<string> ans;

    void helper(int i,string &s,int turnedOn)
    {
        if(turnedOn==0)
        {
            string s1=s.substr(0,4);
            string s2=s.substr(4);

            int x=0,y=0;
            int k=0;
            for(int j=0;j<s1.length();j++)
            {
                if(s1[j]=='1')
                {
                    x+=pow(2,k);
                }
                k++;
            }
            if(x>11)return;
            
            if(x==0)
            {
                s1="0";
            }
            else
            {
                s1=to_string(x);
            }

            k=0;
            for(int j=0;j<s2.length();j++)
            {
                if(s2[j]=='1')
                {
                    y+=pow(2,k);
                }
                k++;
            }
            if(y>59)return;
            if(y==0)
            {
                s2="00";
            }
            else
            {
                s2=to_string(y);
            }
            if(s2.length()==1)
            {
                s2+='0';
                reverse(s2.begin(),s2.end());
            }

            s1+=':';
            s1+=s2;
            ans.push_back(s1);
            return;
        }

        for(int j=i;j<s.length();j++)
        {
            s[j]='1';
            helper(j+1,s,turnedOn-1);
            s[j]='0';
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {

        string s="0000000000";

        helper(0,s,turnedOn);

        return ans;        
        
    }
};