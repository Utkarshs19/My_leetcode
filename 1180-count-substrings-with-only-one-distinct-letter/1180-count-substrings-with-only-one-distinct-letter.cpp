class Solution {
public:
    int countLetters(string s) {

        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            map<char,int> m;
            for(int j=i;j<s.length();j++)
            {
                m[s[j]]++;
                if(m.size()==1)ans++;
            }
        }
        return ans;
        
    }
};