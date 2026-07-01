class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        set<int> st;
        for(int i=0;i<n;i++)st.insert(i);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        sort(meetings.begin(),meetings.end());
        map<int,int> m;
        for(int i=0;i<meetings.size();i++)
        {   
            while(!pq.empty() && meetings[i][0]>=pq.top().first)
            {
                st.insert(pq.top().second);
                pq.pop();
            }

            if(!st.empty())
            {
                auto it=st.begin();
                int room=*it;
                m[room]++;
                pq.push({meetings[i][1],room});
                st.erase(room);
            }   
            else
            {
                auto [finish,room]=pq.top();
                pq.pop();
                m[room]++;
                pq.push({finish+(meetings[i][1]-meetings[i][0]),room});
            }
        }

        int maxi=0;
        for(auto i:m)
        {
            maxi=max(maxi,i.second);
        }
        for(auto i:m)
        {
            if(maxi==i.second)return i.first;
        }
        return -1;

    }
};