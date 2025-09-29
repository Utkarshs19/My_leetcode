class Solution {
public:
    int numberOfSubstrings(string s, int k) {

        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            map<char,int> m;
            for(int j=i;j<s.length();j++)
            {
                m[s[j]]++;
                if(m[s[j]]>=k){
                ans+=(s.length()-j);
                m.clear();
                break;}
            }
        } 

        return ans;
        
    }
};