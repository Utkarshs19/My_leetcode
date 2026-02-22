class Solution {
public:
    map<int,int> m1,m2,m;
    
    int helper(int n)
    {
        int pro=1;
        while(n>0)
        {
            pro=pro*n;
            n--;
        }
        return pro;
    }
    bool isDigitorialPermutation(int n) {

        m[0]=1;
        m[1]=1;
        int sum=0;
        int x=n;
        while(n>0)
        {
            m1[n%10]++;
            n=n/10;
        }
        while(x>0)
        {
            int y=x%10;

            if(m.count(y))
            {
                sum+=m[y];
            }
            else
            {
                m[y]=helper(y);
                sum+=m[y];
            }
        
            x=x/10;
        }

        while(sum>0)
        {
            m2[sum%10]++;
            sum=sum/10;
        }
       
        
        return m1==m2;
        
    }
};