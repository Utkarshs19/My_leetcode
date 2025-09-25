class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        int ans=0;
        
        while(true)
        {
            for(int i=0;i<target.length();i++)
            {
                if(m.find(target[i])!=m.end())
                {
                    m[target[i]]--;
                    if(m[target[i]]==0)m.erase(target[i]);
                }
                else
                {
                    return ans;
                }
            }
            ans++;
        }

        return ans;
        
    }
};