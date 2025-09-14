class Solution {
public:
    string toLower(string s)
    {
        for(int i=0;i<s.length();i++)
        s[i]=tolower(s[i]);

        return s;
    }

    string changeVowel(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            s[i]='*';
        }

        return s;

    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        set<string> st(wordlist.begin(),wordlist.end());

        map<string,string> m1,m2;

        for(int i=0;i<wordlist.size();i++)
        {
            string s=wordlist[i];

            string s_lower=toLower(s);

            string vowel=changeVowel(s_lower);

            if(!m1.count(s_lower))
            m1[s_lower]=s;

            if(!m2.count(vowel))
            m2[vowel]=s;
        }

        vector<string> ans;

        for(int i=0;i<queries.size();i++)
        {
            string s=queries[i];

            if(st.count(s))ans.push_back(s);
            else
            {
                string lower=toLower(s);
                string v=changeVowel(lower);

                if(m1.count(lower))
                ans.push_back(m1[lower]);
                else if(m2.count(v))
                ans.push_back(m2[v]);
                else
                ans.push_back("");
            }
        }

        return ans;
    }
};