class Solution {
public:
    int maxRepOpt1(string text) {

        vector<pair<char,int>> v;

        map<char,int> m;

        v.push_back({text[0],1});
        m[text[0]]++;
        for(int i=1;i<text.length();i++)
        {
            m[text[i]]++;
            if(text[i]==v.back().first)
            {
                int x=v.back().second;
                v.pop_back();
                v.push_back({text[i],x+1});
            }
            else
            {
                v.push_back({text[i],1});
            }
        }
        
        int ans=0;

        for(int i=0;i<v.size();i++)
        {
            char c=v[i].first;
            int len=v[i].second;

            ans=max(ans,min(len+1,m[c]));

            if(i>0 && i<v.size()-1)
            {
                if((v[i-1].first==v[i+1].first) && v[i].second==1)
                {
                    int l=v[i-1].second+v[i+1].second;

                    if(m[v[i-1].first]>l)l++;

                    ans=max(ans,l);

                }
            }
        }

        return ans;

    }
};