class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int countOfSubstrings(string word, int k) {

        int ans=0;

        for(int i=0;i<word.length();i++)
        {
            unordered_map<char,int> m;
            int consonant=0;
            for(int j=i;j<word.length();j++)
            {
                if(isVowel(word[j]))
                m[word[j]]++;
                else
                consonant++;

                if(m.size()==5 && consonant==k)
                ans++;
            }
        }
        return ans;
    }
};