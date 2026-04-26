class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &inSubset) {
        vis[node] = 1;
        for (auto nei : adj[node]) {
            if (!vis[nei] && inSubset[nei]) {
                dfs(nei, adj, vis, inSubset);
            }
        }
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {

        int n = nums.size();

        vector<vector<int>> adj(n);
        for (int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            vector<int> nodes;
            vector<int> inSubset(n, 0);
            int sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    nodes.push_back(i);
                    inSubset[i] = 1;
                    sum += nums[i];
                }
            }

            if (sum % 2 != 0) continue;

            vector<int> vis(n, 0);
            dfs(nodes[0], adj, vis, inSubset);

            int count = 0;
            for (int x : nodes) {
                if (vis[x]) count++;
            }

            if (count == nodes.size()) {
                ans++;
            }
        }

        return ans;
    }
};