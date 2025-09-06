class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {

        vector<int> ans;

        vector<int> v;

        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            map<char,int> m;
            for(int j=0;j<str.length();j++)
            m[str[j]]++;

            for(auto k:m)
            {v.push_back(k.second);
            break;}
        }
        
        vector<int> v1;
        for(int i=0;i<queries.size();i++)
        {
            string str=queries[i];
            map<char,int> m;
            for(int j=0;j<str.length();j++)
            m[str[j]]++;

            for(auto k:m)
            {v1.push_back(k.second);
            break;}
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v1.size();i++)
        {
            int x=0;
            for(int j=0;j<v.size();j++)
            {
                if(v1[i]<v[j]){
                x+=(v.size()-j);
                break;
                }
            }
            ans.push_back(x);
        }

        return ans;
        
    }
};