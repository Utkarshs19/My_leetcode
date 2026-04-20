class Solution {
public:
    vector<int> ans;

    void helper(int i,int n,int k,int num)
    {
        if(i==n)
        {
            ans.push_back(num);
            return;
        }

        int x=num%10;
        if(x-k>=0)
        {
            num=num*10+(x-k);
            helper(i+1,n,k,num);
            num=num/10;
        }
        if(x+k<10)
        {
            num=num*10+(x+k);
            helper(i+1,n,k,num);
            num=num/10;
        }

    }

    vector<int> numsSameConsecDiff(int n, int k) {

        for(int i=1;i<=9;i++)
        helper(1,n,k,i);

        return ans;
        
    }
};