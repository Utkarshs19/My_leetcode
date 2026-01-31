class Solution {
public:

    bool check(string str ,int x)
    {
        if(str=="" && x==0)return true;
        if(x<0)return false;

        bool ans=false;

        for(int i=0;i<str.length();i++)
        {
            string left=str.substr(0,i+1);
            string right=str.substr(i+1);

            int y=stoi(left);

            if(check(right,x-y))
            {
                ans=true;
                break;
            }

        }

        return ans;

    }

    int punishmentNumber(int n) {

        int ans=0;

        for(int i=1;i<=n;i++)
        {
            string str=to_string(i*i);
            int square=i*i;
            if(check(str,i))ans+=square;
        }

        return ans;
        
    }
};