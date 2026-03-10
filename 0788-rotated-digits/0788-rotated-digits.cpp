class Solution {
public:

    bool helper(int x)
    {
        int y=x;
        bool ans=false;
        while(y>0)
        {   
            if(y%10==3 || y%10==4 || y%10==7)return false;
            if(y%10==2 || y%10==5 || y%10==6 || y%10==9)ans=true;
            y=y/10;
        }

        return ans;
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