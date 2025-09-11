class Solution {
public:
    string sortVowels(string s) {
       set<char> st={'a','e','i','o','u','A','E','I','O','U' };
        set<int> s1;
        string str="";
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())
            {   
                s1.insert(i);
                str+=s[i];
            }

        }

        sort(str.begin(),str.end());

        int k=0;

        for(int i=0;i<s.length();i++)
        {
            if(s1.find(i)!=s1.end())
            {
                s[i]=str[k];
                k++;
            }
        }
        return s;
       
    }
};