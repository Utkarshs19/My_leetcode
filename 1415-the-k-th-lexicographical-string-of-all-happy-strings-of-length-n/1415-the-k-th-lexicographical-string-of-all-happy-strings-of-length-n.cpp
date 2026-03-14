class Solution {
public:

    string ans="";
    int cnt=0;
    void helper(int i,int n,int k,string s)
    {
        if(i==n)
        {
            cnt++;
            if(cnt==k)
            ans=s;
            return;
        }

        for(int j=0;j<3;j++)
        {
            if(i-1>=0 && s.back()!='a'+j)
            {
                s+=('a'+j);
                helper(i+1,n,k,s);
                s.pop_back();
            }
            if(i==0)
            {
                s+=('a'+j);
                helper(i+1,n,k,s);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {

        string s;
        helper(0,n,k,s);

        return ans;
        
    }
};