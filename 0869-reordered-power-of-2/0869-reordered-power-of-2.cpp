class Solution {
public:

    string helper(int n)
    {
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {

        string target=helper(n);

        for(int i=0;i<=30;i++)
        {
            if(helper(1<<i)==target)return true;
        }
        return false;
        
    }
};