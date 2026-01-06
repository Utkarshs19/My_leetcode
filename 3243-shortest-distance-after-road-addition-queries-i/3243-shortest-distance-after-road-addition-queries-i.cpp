class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<int> ans(queries.size(), -1);
        map<int, vector<int>> m;

        for (int i = 0; i < queries.size(); i++) {

            m[queries[i][0]].push_back(queries[i][1]);

            queue<int> q;
            vector<int> vis(n, 0);

            q.push(0);
            vis[0] = 1;

            int cnt = 0;
            bool found = false;

            while (!q.empty() && !found) {
                int size = q.size();

                for (int s = 0; s < size; s++) {
                    int node = q.front();
                    q.pop();

                    if (node == n - 1) {
                        ans[i] = cnt;
                        found = true;
                        break;
                    }

                    if (node + 1 < n && !vis[node + 1]) {
                        vis[node + 1] = 1;
                        q.push(node + 1);
                    }

                    if (m.count(node)) {
                        for (int nxt : m[node]) {
                            if (!vis[nxt]) {
                                vis[nxt] = 1;
                                q.push(nxt);
                            }
                        }
                    }
                }

                cnt++;
            }
        }

        return ans;
    }
};
