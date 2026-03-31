class Solution {
public:
    string generateString(string str1, string str2) {
        
        int n=str1.length();
        int m=str2.length();

        string ans(n+m-1,'.');

        for(int i=0;i<n;i++)
        {
            if(str1[i]=='F')continue;
            for(int j=0;j<m;j++)
            {
                if(ans[i+j]!='.' && ans[i+j]!=str2[j])return "";
                ans[i+j]=str2[j];
            }
        }

        string str=ans;
        for(auto &i:ans)
        {
            if(i=='.')i='a';
        }

        for(int i=0;i<n;i++)
        {
            if(str1[i]=='T')continue;
            if(string(ans.begin()+i,ans.begin()+i+m)!=str2)continue;

            bool flag=false;
            for(int j=i+m-1;j>=i;j--)
            {
                if(str[j]=='.'){
                    ans[j]='b';
                    flag=true;
                    break;
                }
            }
            if(!flag)return "";
        }

        return ans;

    }
};