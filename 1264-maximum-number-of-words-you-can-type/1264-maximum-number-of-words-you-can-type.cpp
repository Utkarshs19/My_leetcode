class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        set<char> st;

        for(auto c:brokenLetters)
        st.insert(c);

        int i=0;
        int cnt=0,words=0;
        for(int j=0;j<=text.length();j++)
        {
            if(text[j]==' '||j==text.length())
            {
                words++;
                while(i<j)
                {
                    if(st.count(text[i]))
                    {cnt++;
                    i=j+1;
                    break;
                    }
                    i++;
                }
            }



        }        
            return words-cnt;
    }
};