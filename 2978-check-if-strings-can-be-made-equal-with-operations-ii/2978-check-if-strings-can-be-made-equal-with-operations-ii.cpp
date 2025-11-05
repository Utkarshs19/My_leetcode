class Solution {
public:
    bool checkStrings(string s1, string s2) {

        if(s1==s2)return true;

        map<char,int> ms1_1,ms1_2;

        map<char,int> ms2_1,ms2_2;


        for(int i=0;i<s1.length();i++)
        {
            if(i%2==0)
            ms1_1[s1[i]]++;
            else
            ms1_2[s1[i]]++;
        }

        for(int i=0;i<s2.length();i++)
        {
            if(i%2==0)
            ms2_1[s2[i]]++;
            else
            ms2_2[s2[i]]++;
        }

        return ms1_1==ms2_1 && ms1_2==ms2_2;
        
    }
};