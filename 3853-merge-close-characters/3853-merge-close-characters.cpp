class Solution {
public:
    string mergeCharacters(string s, int k) {

        map<char,int> m;
        string ans;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(m.count(s[i]))
            {
                if(i-m[s[i]]-cnt<=k){
                    cnt++;
                    continue;}
                else{
                ans+=s[i];
                m[s[i]]=i-cnt;
                }
            }
            else
            {
                ans+=s[i];
                m[s[i]]=i-cnt;
            }
        }

        return ans;

    }
};