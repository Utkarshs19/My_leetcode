class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        vector<int> ans;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> >pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >p;


        for(int i=0;i<tasks.size();i++)
        {
            pq.push({tasks[i][0],tasks[i][1],i});
        }


        long long  time=0;

        while(!pq.empty() || !p.empty())
        {
            while(!pq.empty() && pq.top()[0]<=time)
            {
                p.push({pq.top()[1],pq.top()[2]});
                pq.pop();
            }

            if(p.empty())
            {
                time=pq.top()[0];
                continue;
            }

            if(!p.empty())
            {
                ans.push_back(p.top().second);
                time+=p.top().first;
                p.pop();
            }

        }


        return ans;

        return {};

    }
};