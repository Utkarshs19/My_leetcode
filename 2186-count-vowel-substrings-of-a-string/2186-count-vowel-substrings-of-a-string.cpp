class Solution {
public:
    int countVowelSubstrings(string word) {

        int ans=0;
        map<char,int> m;

        for(int i=0;i<word.length();i++)
        {   
            m.clear();
            for(int j=i;j<word.length();j++)
            {
                if(word[j]=='a'||word[j]=='e'||word[j]=='i'||word[j]=='o'||word[j]=='u')
                {
                    m[word[j]]++;
                    if(m.size()==5)
                    {
                        ans++;
                    }
                }
                else
                break;

            }
        }

        return ans;
        
    }
};