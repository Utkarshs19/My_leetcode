class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

        map<char,set<string>> m;

        for(int i=0;i<ideas.size();i++)
        {
            m[ideas[i][0]].insert(ideas[i].substr(1));
        }
        long long ans=0;

        for(auto i:m)
        {
            for(auto j:m)
            {
                if(i.first>=j.first)continue;

                int cnt=0;
                    for(auto &b:j.second)
                    {
                        if(i.second.count(b))cnt++;
                    }
                
                int len1=i.second.size()-cnt;
                int len2=j.second.size()-cnt;

                ans+=2*(len1*len2);
            }
        }
        return ans;
    }
};