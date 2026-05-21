class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {

        map<string,int> m;
        m[word1]=-1;
        m[word2]=-1;
        int ans=1e9;

        for(int i=0;i<wordsDict.size();i++)
        {
            if(wordsDict[i]==word1)
            {
                if(m[word2]!=-1)
                {
                    ans=min(ans,i-m[word2]);
                }
                m[word1]=i;
            }

            if(wordsDict[i]==word2)
            {
                if(m[word1]!=-1)
                {
                    ans=min(ans,i-m[word1]);
                }
                m[word2]=i;
            }

        }

        return ans;
        
    }
};