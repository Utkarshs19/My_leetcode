class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int k=1;
        for(int i=0;i<sentence.length();i++)
        {
            if(i==0||sentence[i-1]==' ')
            {
                if(sentence.substr(i,searchWord.length())==searchWord)
                return k;

                k++;
            }
        }

        return -1;
        
    }
};