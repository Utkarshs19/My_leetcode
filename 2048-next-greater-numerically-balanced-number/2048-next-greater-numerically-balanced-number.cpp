class Solution {
public:

    set<int> st;

    void perm(int i,string s)
    {
        if(i==s.length())
        {
            int x=0;
            for(int j=0;j<s.length();j++)
            {
                x=x*10+(s[j]-'0');
            }
            st.insert(x);
            return;
        }

        for(int j=i;j<s.length();j++)
        {
            swap(s[j],s[i]);
            perm(i+1,s);
            swap(s[j],s[i]);
        }
    }



    int nextBeautifulNumber(int n) {

        vector<int> v={1,22,122,333,1333,22333,4444,14444,224444,122333,55555,155555,666666};

        for(int i=0;i<v.size();i++)
        {
            string s=to_string(v[i]);
            perm(0,s);
        }

        vector<int> balanced(st.begin(),st.end());

        sort(balanced.begin(),balanced.end());
        balanced.push_back(1224444);
        for(int i=0;i<balanced.size();i++)
        {
            cout<<balanced[i]<<endl;
        }

        int i=0,j=balanced.size()-1;

        while(i<=j)
        {
            int mid=i+(j-i)/2;

            if(balanced[mid]<=n)i=mid+1;
            else
            j=mid-1;
        }

        return balanced[i];
        
        return n;

    }
};