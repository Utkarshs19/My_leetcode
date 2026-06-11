class Solution {
public:
    set<long long> st;
    int low,high;
    void helper(long long num)
    {
        if(num>high)return;

        if(num>=low && num<=high)
        {
            st.insert(num);
        }

        int x=num%10;

        if(x!=9)
        {
            x=x+1;
            num=num*10+x;
            helper(num);
            num=num/10;
        }
        x=num%10;
        if(x!=0)
        {
            x=x-1;
            num=num*10+(x);
            helper(num);
            num=num/10;
        }
    }
    vector<int> countSteppingNumbers(int low, int high) {
        
        this->low=low;
        this->high=high;

        for(int i=0;i<=9;i++)
        {
            helper(i);
        }
        vector<int> ans(st.begin(),st.end());

        return ans;
    }
};