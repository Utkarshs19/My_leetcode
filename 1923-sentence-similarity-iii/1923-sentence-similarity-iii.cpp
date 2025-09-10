class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {

        list<string> v1,v2;

        int i=0;
        string s="";
        while(i<=s1.length())
        {
            if(s1[i]==' '||i==s1.length())
            {
                v1.push_back(s);
                s="";
            }
            else
            s+=s1[i];
            i++;
        }



        i=0;
        s="";

        while(i<=s2.length())
        {
            if(s2[i]==' '||i==s2.length())
            {
                v2.push_back(s);
                s="";
            }
            else
            s+=s2[i];
            i++;
        }

      

        i=0;
        int j=0;

        while(!v1.empty()&&!v2.empty()&&v1.front()==v2.front())
            {
                v1.pop_front();
                v2.pop_front();
            }
        

        while(!v1.empty()&&!v2.empty()&&(v1.back()==v2.back()))
        {
                v1.pop_back();
                v2.pop_back();
        }

        return v1.empty()||v2.empty();

        
    }
};