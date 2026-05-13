class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        vector<int> ans;

        map<string,int> m;
        string s;
        for(auto i:chunks)s+=i;
        string str;
        for(int i=0;i<s.length();i++)
        {
            if(islower(s[i]))str+=s[i];
            else if(s[i]=='-')
            {
                if(str.length()!=0 && i+1<s.length() && islower(s[i+1]))str+='-';
                else
                {
                    if(str.length()!=0)
                    {
                        m[str]++;
                        str="";
                    }
                }
            }
            else
            {
                if(str.length()!=0)
                {
                    m[str]++;
                    str="";
                }
            }
        }

        if(str.length()!=0)m[str]++;

        for(int i=0;i<queries.size();i++)
        {   
            if(m.count(queries[i]))
            ans.push_back(m[queries[i]]);
            else
            ans.push_back(0);
        }
        return ans;
    }
};