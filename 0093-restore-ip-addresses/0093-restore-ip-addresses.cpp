class Solution {
public:
    bool check(string str)
    {
        if(str.length()==1)return true;

        if(str.length()>3 || str[0]=='0')return false;

        if(stoi(str)>255)return false;

        return true;
    }
    vector<string> restoreIpAddresses(string s) {

        if(s.length()>12)return {};
        int n=s.length();

        vector<string> ans;

        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    if(i+j+k<n && i+j+k+3>=n)
                    {
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(i+j,k);
                        string d=s.substr(i+j+k);

                        if(check(a) && check(b) && check(c) && check(d))
                        {
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};