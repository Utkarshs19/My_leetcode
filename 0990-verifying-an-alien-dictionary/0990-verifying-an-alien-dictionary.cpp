class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        map<char,int> m;

        for(int i=0;i<order.length();i++)
        {
            m[order[i]]=i;
        }

        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
            string str1=words[i];
            string str2=words[j];

            int a=0,b=0;

            while(a<str1.length() && b<str2.length())
            {
                if(str1[a]!=str2[b])
                {
                    if(m[str1[a]]>m[str2[b]])return false;
                    else break;
                   
                }
                a++;
                b++;

                if(b==str2.length() && a<str1.length())return false;
            }
            }
        }
        
        return true;
    }
};