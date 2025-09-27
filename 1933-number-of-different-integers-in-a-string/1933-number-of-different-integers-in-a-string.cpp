class Solution {
public:
    int numDifferentIntegers(string word) {
        
        word+='z';
        set<string> st;
        long long int x=0;
        string s="";
        for(int i=0;i<word.length();i++)
        {
            if(!isalpha(word[i]))
            {

                s+=word[i];
            }
            else
            {
                if(s!=""){ 

                int j=0;
                while(j<s.length())
                {
                    if(s[j]=='0')j++;
                    else
                    break;
                }
                   
                st.insert(s.substr(j));
                }
                s="";
                
            }
            
        }

        return st.size();
        
    }
};