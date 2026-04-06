class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> str={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for(int i=0;i<words.size();i++)
        {
            string s;
            for(int j=0;j<words[i].length();j++)
            {
                s+=str[words[i][j]-'a'];
            }
            st.insert(s);
        }
        return st.size();

    }
};