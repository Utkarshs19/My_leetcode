class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string removeVowels(string s) {

    string ans;

    for(int i=0;i<s.length();i++)
    {
        if(!isVowel(s[i]))ans+=s[i];
    }
    return ans;
        
    }
};