class Solution {
public:
    set<int> st;
    vector<int> ans;
    void dfs(int node,map<int,vector<int>> &m)
    {
        ans.push_back(node);
        st.insert(node);

        for(auto i:m[node])
        {
            if(!st.count(i))
            {
                st.count(i);
                dfs(i,m);
            }
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {

        map<int,vector<int>> m;

        for(int i=0;i<ppid.size();i++)
        {
            m[ppid[i]].push_back(pid[i]);
        }

        dfs(kill,m);

        return ans;
        
    }
};