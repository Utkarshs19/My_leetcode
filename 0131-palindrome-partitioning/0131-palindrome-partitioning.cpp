class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;

    bool isPal(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }

    void helper(int i,string &s)
    {
        if(i>=s.length())
        {
            ans.push_back(v);
            return;
        }

        for(int j=i;j<s.length();j++)
        {
            if(isPal(s,i,j))
            {
                v.push_back(s.substr(i,j-i+1));

                helper(j+1,s);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        helper(0,s);

        return ans;

    }
};