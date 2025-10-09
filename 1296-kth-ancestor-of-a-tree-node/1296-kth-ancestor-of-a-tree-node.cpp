class TreeAncestor {
public:

     int N=5e4+1 ,M=20;

   vector<vector<int>> edges;

    vector<vector<int>>  parentTable;


    void dfs(int cur,int parent)
    {
        parentTable[cur][0]=parent;

        for(int j=1;j<M;j++){
            if(parentTable[cur][j-1]==-1)
            parentTable[cur][j]=-1;
            else
            parentTable[cur][j]=parentTable[parentTable[cur][j-1]][j-1];
        }
        for(auto i:edges[cur])
        {
            if(i!=parent)
            dfs(i,cur);
        }
    }


    TreeAncestor(int n, vector<int>& parent) {

        this->N = n;
        M = 20; 
        int root=-1;
        parentTable.assign(N, vector<int>(M, -1));
        edges.resize(N);

        for(int i=0;i<n;i++)
        {
            if (parent[i] == -1){
                root=i;
            }
            else
            edges[parent[i]].push_back(i);
        }

        dfs(root,-1);

    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=M-1;i>=0 && node!=-1;i--)
        {
            if(k & (1<<i))
            node=parentTable[node][i];
        }

        return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */