class Solution {
public:
    vector<string> ans;
    map<string,multiset<string>> m;

    void dfs(string str)
    {
        while(!m[str].empty())
        {
            auto u=*m[str].begin();
            m[str].erase(m[str].begin());
            dfs(u);
        }
        ans.push_back(str);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
            for(int i=0;i<tickets.size();i++)
            {
                m[tickets[i][0]].insert(tickets[i][1]);
            }

            dfs("JFK");

            reverse(ans.begin(),ans.end());
            return ans;

    }
};