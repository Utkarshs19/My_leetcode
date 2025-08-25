class Solution {
public:
    string clearStars(string s) {

        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='*')
            pq.push({s[i],-i});
            else
            pq.pop();
        }
        
        map<int,char> m;

        while(!pq.empty())
        {
            m[(-1*pq.top().second)]=pq.top().first;
            pq.pop();
        }
        string ans="";

        for(auto i:m)
        {
            ans+=i.second;
        }
        
        return ans;
        
    }
};