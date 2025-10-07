class Solution {
public:

   vector<long long> subtree;
    int n;
    map<int,vector<int>> m;
    
    int dfs(int node) {
        long long size = 1;
        for (int c : m[node])
            size += dfs(c);
        subtree[node] = size;
        return size;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        
        int n=parents.size();
        
        subtree.resize(n, 0);

        for(int i=0;i<parents.size();i++)
        {
            if(parents[i]!=-1)
            {
                m[parents[i]].push_back(i);
                // m[i].push_back(parents[i]);
            }
        }

        dfs(0);

        long long int pro=1;
        map<int,int> m1;

        for(int i=0;i<n;i++)
        {
            long long mul=1;
            long long remain=n-subtree[i];

            if(remain>0)
            mul=mul*remain;

            for(auto j:m[i])
            {
                mul=mul*subtree[j];
            }

            pro=max(pro,mul);
            m1[mul]++;

        }

        return m1[pro];
        
    }
};