class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> st;
        for(int i=0;i<k;i++)
        {
            st.insert(i);
        }
        for(int i=0;i<arrival.size();i++)
        {
            while(!pq.empty())
            {
                if(pq.top().first<=arrival[i])
                {
                    st.insert(pq.top().second);
                    pq.pop();
                }
                else
                break;
            }
            if(st.empty())continue;
            auto it=st.lower_bound(i%k);
            if(it==st.end())
            {
                it=st.begin();
            }

            int server=*it;
            st.erase(server);
            m[server]++;
            pq.push({arrival[i]+load[i],server});
        }

        int maxi=INT_MIN;
        for(auto i:m)
        {
            maxi=max(maxi,i.second);
        }
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second==maxi)ans.push_back(i.first);
        }
        return ans;
        
    }
};