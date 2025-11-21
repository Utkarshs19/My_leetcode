class Solution {
public:
    int countPalindromicSubsequence(string s) {


        map<char,vector<int>> m;

        for(int i=0;i<s.length();i++)
        {
            m[s[i]].push_back(i);
        }

        set<string> st;

        for(auto i:m)
        {
            vector<int> v=i.second;
            if(v.size()>=2)
            {
                if(v[v.size()-1]-v[0]-1>0)
                {
                    string str="";
                    str+=s[v[0]];
                    
                    for(int j=v[0]+1;j<v[v.size()-1];j++)
                    {
                        str+=s[j];
                        str+=s[v[v.size()-1]];

                        st.insert(str);
                        // cout<<str<<endl;
                        str="";
                        str=s[v[0]];
                    }

                }
            }
        }

        return st.size();
        
    }
};