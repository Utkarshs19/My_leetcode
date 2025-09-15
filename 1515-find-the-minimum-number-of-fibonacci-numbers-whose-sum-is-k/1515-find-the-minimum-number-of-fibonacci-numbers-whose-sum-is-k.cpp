class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        if(k==0)return 0;
        int x1=1;
        int x2=1;

        while(x2<=k)
        {
            if(x1==k)return 1;

            int x3=x2;
            x2=x1+x2;
            x1=x3;

        }

        cout<<x1<<endl;
        
        return 1+findMinFibonacciNumbers(k-x1);
    }
};