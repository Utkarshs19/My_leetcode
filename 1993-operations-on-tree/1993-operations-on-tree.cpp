class LockingTree {
public:
    map<int,int> m;
    vector<vector<int>> adj;
    set<int> st;

    vector<int> par;
    int n;

    void dfs(int node,vector<int> &vis,int &cnt)
    {
        vis[node]=1;
        if(m.count(node)){cnt++;
        st.insert(node);
        }

        for(auto i:adj[node])
        {
            if(vis[i]==-1)
            dfs(i,vis,cnt);
        }
    }

    void dfs1(int node,int &cnt2)
    {
        if(node==-1)return;
        if(m.count(node))cnt2++;

        dfs1(par[node],cnt2);
    }    
    LockingTree(vector<int>& parent) {

        n=parent.size();
        par=parent;

        adj.resize(n);

        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back(i);
        }
        
    }
    
    bool lock(int num, int user) {
        
        if(m.count(num))
        {
            return false;
        }
        m[num]=user;
        return true;

    }
    
    bool unlock(int num, int user) {
        if(m.count(num))
        {
            if(m[num]==user)
            {
                m.erase(num);
                return true;
            }
            else
            return false;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {

        if(m.count(num))return false;

        int cnt=0;
        vector<int> vis(n,-1);
        st.clear();
        dfs(num,vis,cnt);
        if(cnt==0)return false;

        int cnt2=0;
        dfs1(num,cnt2);
        if(cnt2>0)return false;

        m[num]=user;
        for(auto i:st)
        {
            m.erase(i);
        }
        return true;

        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */