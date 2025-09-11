class Solution {
public:
    string sortVowels(string s) {
       set<char> st={'a','e','i','o','u','A','E','I','O','U' };
        map<char,int> m;
        
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())
            {   
               m[s[i]]++;
            }

        }

        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())
            {   
               for(auto &it:m)
               {
                    if(it.second>0){
                    s[i]=it.first;
                    it.second--;
                    break;
                    }
               }
            }

        }


        return s;


    }
};