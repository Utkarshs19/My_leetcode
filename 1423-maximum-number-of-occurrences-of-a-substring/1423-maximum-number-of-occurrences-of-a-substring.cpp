class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

        int ans=0;

        int i=0,j=0;

        map<char,int> m;

        map<string,int> m1;

        while(j<s.length())
        {
            m[s[j]]++;

            while(j-i+1>minSize)
            {
                m[s[i]]--;
                if(m[s[i]]<=0)
                m.erase(s[i]);
                i++;
            }


            if(j-i+1==minSize  && m.size()<=maxLetters){
                m1[s.substr(i,j-i+1)]++;
                ans=max(ans,m1[s.substr(i,j-i+1)]);
            }


            j++;

        }

        return ans;

    }
};