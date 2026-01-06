class Solution {
public:
    int maximumLength(string s) {
        
        map<pair<string,set<char>>,int> m;

        for(int i=0;i<s.length();i++)
        {   
            string str="";
            set<char> st;
            for(int j=i;j<s.length();j++)
            {   
                str+=s[j];
                st.insert(s[j]);
                m[{str,st}]++;
            }
        }

        int maxi=-1;

        for(auto i:m)
        {
            if(i.second>=3)
            {
                if(i.first.second.size()==1)
               if(int(i.first.first.length())>maxi){
                maxi=i.first.first.length();}
            }
        }
        return maxi;

    }
};