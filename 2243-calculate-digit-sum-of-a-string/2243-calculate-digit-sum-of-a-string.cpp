class Solution {
public:
    string digitSum(string s, int k) {
        
        int len=s.length();

        while(len>k)
        {
            string str;
            int c=0;
            int x=0;
            for(int i=0;i<s.length();i++)
            {
                x+=(s[i]-'0');
                c++;
                if(c==k)
                {
                    str+=to_string(x);
                    c=0;
                    x=0;
                }
            }
            if(c>0)str+=to_string(x);
            len=str.length();
            s=str;

            cout<<s<<endl;
        }

        return s;

    }
};