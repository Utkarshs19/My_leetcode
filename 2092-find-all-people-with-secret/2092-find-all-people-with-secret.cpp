class Solution {
public:
    void dfs(int u,vector<vector<pair<int,int>>> &adj, vector<int> &timeKnown)
    {
        for (auto &[v, t] : adj[u]) {

            if (t < timeKnown[u]) continue;

            if (timeKnown[v] <= t) continue;

            timeKnown[v] = t;
            dfs(v, adj, timeKnown);
        }
    }

    vector<int> findAllPeople(int n,vector<vector<int>>& meetings,int firstPerson)
    {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &m : meetings) {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }

        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(),
                 [](auto &a, auto &b) {
                     return a.second < b.second;
                 });
        }

        const int INF = 1e9;
        vector<int> timeKnown(n, INF);

        timeKnown[0] = 0;
        timeKnown[firstPerson] = 0;

        dfs(0, adj, timeKnown);
        dfs(firstPerson, adj, timeKnown);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (timeKnown[i] != INF)
                ans.push_back(i);
        }

        return ans;
    }
};
