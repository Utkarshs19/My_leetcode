class Solution {
public:
    bool closeStrings(string word1, string word2) {

        map<char,int> m1,m2;

        for(int i=0;i<word1.length();i++)
        m1[word1[i]]++;

        for(int i=0;i<word2.length();i++)
        m2[word2[i]]++;

        if(word1.length()!=word2.length())return false;

        if(m1==m2)return true;

        vector<int> v1,v2;

        for(auto i:m1)
        {
            if(m2.find(i.first)==m2.end())return false;
        }

        for(auto i:m2)
        {
            if(m1.find(i.first)==m1.end())return false;
        }

        for(auto i:m1)
        v1.push_back(i.second);
        for(auto i:m2)
        v2.push_back(i.second);

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return v1==v2;
        
    }
};