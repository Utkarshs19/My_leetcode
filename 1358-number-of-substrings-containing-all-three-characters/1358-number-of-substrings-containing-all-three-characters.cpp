class Solution {
public:
    int numberOfSubstrings(string s) {

        int cnt=0;
        int i=0,j=0;
        map<char,int> m;
        while(j<s.length())
        {
            m[s[j]]++;
            
            while(m.size()==3)
            {
                cnt+=s.length()-j;
                m[s[i]]--;
                if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            j++;
        }
        return cnt;
        
    }
};