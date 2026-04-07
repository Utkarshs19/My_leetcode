class Solution {
public:
    set<int> st;

    bool power(int num)
    {
        if(num==1)return true;
        if(num<=0 || num%2==1)return false;

        return power(num/2);
    }

    void helper(int i,string s)
    {
        if(i==s.length())
        {
            if(s[0]=='0')return;

            int x=0;
            for(int k=0;k<s.length();k++)
            {
                x=x*10+(s[k]-'0');
            }
            st.insert(x);
            return ;
        }

        for(int j=i;j<s.length();j++)
        {
            swap(s[j],s[i]);
            helper(i+1,s);
            swap(s[j],s[i]);
        }
    }

    bool reorderedPowerOf2(int n) {
        
        string s=to_string(n);
        helper(0,s);

        for(auto i:st)
        {
            if(power(i))return true;
        }
        return false;
        
    }
};