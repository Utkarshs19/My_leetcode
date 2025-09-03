class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {

        int n=s.length()/k;

        map<string,int> m;

        for(int i=0;i<s.length();)
        {
           m[(s.substr(i,n))]++;
            i+=n;
        }

        for(int i=0;i<t.length();)
        {
           if (m.find(t.substr(i, n)) == m.end()) return false;

           m[t.substr(i,n)]--;

           if(m[t.substr(i,n)]==0)m.erase((t.substr(i,n)));
            i+=n;
        }

        return true;


        
    }
};