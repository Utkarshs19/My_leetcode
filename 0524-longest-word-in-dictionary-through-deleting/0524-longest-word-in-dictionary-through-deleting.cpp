class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        map<int,vector<string>> m;

        for(int i=0;i<dictionary.size();i++)
        {
            m[dictionary[i].length()].push_back(dictionary[i]);
        }

        priority_queue<pair<int,vector<string>>> pq;

        for(auto i:m)
        {
            int x=i.first;
            vector<string> v=i.second;
            sort(v.begin(),v.end());

            pq.push({x,v});
        }

        while(!pq.empty())
        {
            vector<string> v=pq.top().second;

            int k=0;
            for(int j=0;j<v.size();j++)
            {
                int a=0;
                 k=0;
                while(a<v[j].length()&&k<s.length())
                {
                    if(v[j][a]==s[k])
                    {a++;
                    k++;
                    }
                    else k++;
                }
                if(a==v[j].length())return v[j];
            }
            pq.pop();
        }

        return "";

        
    }
};