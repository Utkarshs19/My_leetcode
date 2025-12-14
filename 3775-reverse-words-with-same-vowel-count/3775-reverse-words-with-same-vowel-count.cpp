class Solution {
public:
    string reverseWords(string s) {

        set<char> st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');

        int i=0,j=0;
        int vowel=0;

        while(j<s.length())
        {
            if(s[j]==' ')
            {
                break;
            }
            else
            {
                if(st.find(s[j])!=st.end())
                vowel++;
            }
            j++;
        }

        j++;
        i=j;
        s+=' ';
        int cnt=0;

        while(j<s.length())
        {
            if(s[j]==' ')
            {

                if(vowel==cnt)
                {
                    int k=j-1;
                    while(k>i)
                    {
                        swap(s[i],s[k]);
                        k--;
                        i++;
                    }
                }
                
                cnt=0;
                i=j+1;
            }
            else
            {
                if(st.find(s[j])!=st.end())
                cnt++;
            }
            j++;
        }

        s.pop_back();

        return s;


        
    }
};