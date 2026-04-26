class Solution {
public:
    string sortVowels(string s) {
        
        set<char> st={'a','e','i','o','u'};

        map<char,int> m;
        map<char,int> m1;

        for(int i=0;i<s.length();i++)
        {
            if(st.count(s[i]))
            {
                m[s[i]]++;
                if(!m1.count(s[i]))
                {
                    m1[s[i]]=i;
                }
            }
        }

        vector<pair<char,pair<int,int>>> v;

        for(auto i:m)
        {
            v.push_back({i.first,{i.second,m1[i.first]}});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.second.first != b.second.first)
            return a.second.first > b.second.first;   
        return a.second.second < b.second.second;     
    });

        vector<char> v1;

        for(int i=0;i<v.size();i++)
        {
            int x=v[i].second.first;
            while(x>0)
            {
                v1.push_back(v[i].first);
                x--;
            }
        }

        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(!st.count(s[i]))continue;
            else
            {
                s[i]=v1[j];
                j++;
            }
        }
        return s;
    }
};