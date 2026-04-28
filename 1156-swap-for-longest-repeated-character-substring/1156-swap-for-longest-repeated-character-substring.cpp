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

        char x=v[0].first;
        if(m[x]>v[0].second)
         ans=v[0].second+1;
        else
        ans=v[0].second;

        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<"  "<<v[i].second<<endl;
        }

        for(int i=1;i<v.size()-1;i++)
        {
            if((v[i-1].first==v[i+1].first) && v[i].second==1)
            { 
                char x=v[i-1].first;

                if(m[x]>v[i-1].second+v[i+1].second)
                {
                    ans=max(ans,v[i-1].second+v[i+1].second+1);
                }
                else
                {
                    ans=max(ans,v[i-1].second+v[i+1].second);
                }
            }
            else if(v[i-1].first==v[i+1].first && v[i].second>1)
            {
                ans=max(ans,v[i-1].second+1);
                ans=max(ans,v[i+1].second+1);
            }
            else
            {
                char x=v[i-1].first;

                if(m[x]>v[i-1].second)
                ans=max(ans,v[i-1].second+1);
                else
                ans=max(ans,v[i-1].second);
            }
        }

        int n=v.size();

        x=v[n-1].first;

        if(m[x]>v[n-1].second)
        ans=max(ans,v[n-1].second+1);
        else
        ans=max(ans,v[n-1].second);

        return ans;

    }
};