class Solution {
public:
    string minimizeStringValue(string s) {

        map<char,int> m;
        for(int i=0;i<26;i++)
        {
            m['a'+i]=0;
        }

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='?')m[s[i]]++;
        }


        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>> >pq;

        for(auto i:m)
        {
            pq.push({i.second,i.first});
        }
        string t="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {
                t+=pq.top().second;
                char x=pq.top().second;
                int y=pq.top().first;
                pq.pop();
                y++;
                pq.push({y,x});
            }
        }

        sort(t.begin(),t.end());
        int k=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {
                s[i]=t[k];
                k++;
            }
        }

        return s;

        
    }
};