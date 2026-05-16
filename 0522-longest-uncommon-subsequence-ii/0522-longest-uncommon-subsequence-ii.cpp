class Solution {
public:
    bool isSub(string a,string b)
    {
        int i=0,j=0;
        while(i<a.length() && j<b.length())
        {
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i==a.length();
    }
    int findLUSlength(vector<string>& strs) {

        int n=strs.size();

        sort(strs.begin(),strs.end(),[](string a,string b){
            return a.length()>b.length();
        });
        

        for(int i=0;i<n;i++)
        {
            bool flag=false;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                
                if(isSub(strs[i],strs[j]))
                    flag=true;
            }
            if(!flag)return strs[i].length();
        }

        return -1;
    }
};