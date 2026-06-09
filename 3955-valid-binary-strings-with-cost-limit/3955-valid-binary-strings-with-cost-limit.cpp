class Solution {
public:
    vector<string> ans;
    void helper(int i,int n,int k,string str,int cost)
    {
        if(i==n)
        {
            if(cost<=k)ans.push_back(str);
            return;
        }

        str+='0';
        helper(i+1,n,k,str,cost);
        str.pop_back();
        if((str.length()>0 && str[str.length()-1]=='0') || str.length()==0 )
        {
            str+='1';
            helper(i+1,n,k,str,cost+i);
            str.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        
        helper(0,n,k,"",0);

        return ans;

    }
};