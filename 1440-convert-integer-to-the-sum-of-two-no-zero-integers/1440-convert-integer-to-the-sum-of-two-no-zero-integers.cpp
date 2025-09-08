class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> v;

        for(int i=1;i<=n;i++)
        {
            int x=i;
            int y=n-i;
            bool flag=true;
            while(x>0)
            {
                if(x%10==0){
                    flag=false;
                    break;
                }
                x=x/10;
            }
            if(flag==false)continue;
            while(y>0)
            {
                if(y%10==0)
                {
                    flag=false;
                    break;
                }
                y=y/10;
            }
            if(flag==false)continue;

            return {i,n-i};
        }
        return v;
    }
};