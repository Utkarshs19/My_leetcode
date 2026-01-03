class Solution {
public:
    int minAnagramLength(string s) {

        vector<int> v;

        for(int i=1;i<s.length();i++)
        {
            if(s.length()%i==0)v.push_back(i);
        }

        for(int k=0;k<v.size();k++)
        {
            map<string,int> m;

            for(int i=0;i<s.length();i+=v[k])
            {
                string str=s.substr(i,v[k]);
                sort(str.begin(),str.end());

                m[str]++;
            }

            if(m.size()==1)
            {
                if((m.begin()->second)*v[k]==s.length())return v[k];
            }
        }
        return s.length();
    }
};