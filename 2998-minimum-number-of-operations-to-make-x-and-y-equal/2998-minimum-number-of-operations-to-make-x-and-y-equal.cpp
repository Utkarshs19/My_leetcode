class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {

        if(y>x)return y-x;
        if(y==x)return 0;

        vector<int> vis(10002,0);
        queue<int> q;
        q.push(x);
        vis[x]=1;
        int step=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int node=q.front();
                q.pop();

                if(node==y)return step;

                if(node%11==0 && !vis[node/11])
                {
                    vis[node/11]=1;
                    q.push(node/11);
                }
                if(node%5==0 && !vis[node/5])
                {
                    vis[node/5]=1;
                    q.push(node/5);
                }

                if(node-1>=0 && !vis[node-1])
                {
                    vis[node-1]=1;
                    q.push(node-1);
                }

                if(node+1<=10001 && !vis[node+1])
                {
                    vis[node+1]=1;
                    q.push(node+1);
                }
            }
            step++;
        }
        
        return -1;
    }
};