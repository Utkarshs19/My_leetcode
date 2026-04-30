class Solution {
public:
    int low, high;
    vector<int> ans;

    void helper(int num)
    {
        if(num>=low && num<=high)
        {
            ans.push_back(num);
        }
        if(num>high)return;

        int x=num%10;
        if(x==9)return;
        num=num*10+(x+1);
        helper(num);

    }

    vector<int> sequentialDigits(int low, int high) {
        
        this->low=low;
        this->high=high;

        for(int i=1;i<=8;i++)
        {
            helper(i);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};