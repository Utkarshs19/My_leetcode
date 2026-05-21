class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {

        vector<vector<int>> ans;

        map<int,priority_queue<int,vector<int>,greater<int>> > m;

        for(int i=0;i<items.size();i++)
        {
            m[items[i][0]].push(items[i][1]);
            if(m[items[i][0]].size()>5)m[items[i][0]].pop();
        }

        for(auto i:m)
        {
            priority_queue<int,vector<int>,greater<int>> pq=i.second;
            int sum=0;
            while(!pq.empty())
            {
                cout<<pq.top()<<endl;
                sum+=pq.top();
                pq.pop();
            }

            ans.push_back({i.first,sum/5});
        }

        return ans;
        
    }
};