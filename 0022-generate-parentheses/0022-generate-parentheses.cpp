class Solution {
public:
    vector<string> ans;
    void helper(int open,int close, string s)
    {
        if(open==0 && close==0)
        {
            ans.push_back(s);
            return;
        }

        if(open>0)
        {
            helper(open-1,close,s+'(');
        }
        if(close>open)
        {
            helper(open,close-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {

        helper(n,n,"");

        return ans;
        
    }
};