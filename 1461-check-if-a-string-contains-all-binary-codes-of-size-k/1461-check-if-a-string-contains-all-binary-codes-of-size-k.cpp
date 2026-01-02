class Solution {
public:
    bool hasAllCodes(string s, int k) {

        map<string,int> m;
        if(s.length()<k)return false;

        for(int i=0;i<s.length()-k+1;i++)
        {
            m[s.substr(i,k)]++;
        }


        if(m.size()==pow(2,k))return true;
        return false;
        
    }
};