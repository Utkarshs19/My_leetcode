class Solution {
public:
    set<int> st;
    map<string,int> m;
    int n;

    void bintoint(string str)
    {
        long long x=0;
        int len=str.length()-1;

        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='1')
            {
                x+=(pow(2,len));
            }
            len--;
        }
        if(x<=0||x>n)return;
        st.insert(x);
    }

    bool queryString(string s, int n) {

        this->n=n;
        
        for(int i=0;i<s.length();i++)
        {   
            string str="";
            for(int j=i;j<min(i+30,int(s.length()));j++)
            {
                str+=s[j];
                if(!m.count(str))
                {
                    m[str]++;
                    bintoint(str);
                }
            }
        }

        return st.size()==n;


        
    }
};