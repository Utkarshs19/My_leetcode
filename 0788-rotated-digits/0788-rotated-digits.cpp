class Solution {
public:

    bool helper(int x)
    {
        int y=x;
        vector<int> v1,v2;
        while(y>0)
        {
            v1.push_back(y%10);
            if(y%10==0 || y%10==1 ||y%10==8)v2.push_back(y%10);
            else if(y%10==2)v2.push_back(5);
            else if(y%10==5)v2.push_back(2);
            else if(y%10==6)v2.push_back(9);
            else if(y%10==9)v2.push_back(6);
            else return false;
            y=y/10;
        }

        return v1!=v2;
    }

    int rotatedDigits(int n) {
        int ans=0;

        for(int i=1;i<=n;i++)
        {
            int x=i;
            if(helper(x))
            ans++;
        }

        return ans;
        
    }
};