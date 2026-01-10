class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<pair<int,char>> pq;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>> > p;

        map<char,int> m;
        for(int i=0;i<tasks.size();i++)
        m[tasks[i]]++;

        for(auto i:m)
        {
            pq.push({i.second,i.first});
        }

        int ans=0;

        while(!pq.empty() || !p.empty())
        {
            while(!p.empty() && p.top().first<=ans)
            {
                char c=p.top().second;
                pq.push({m[c],c});
                p.pop();
            }

            if(!pq.empty()){
                char x=pq.top().second;
                int y=pq.top().first;
                pq.pop();

                m[x]--;

                if(m[x]>0)
                {
                    p.push({ans+n+1,x});
                }
            }
            ans++;
        }

        return ans;
        
    }
};