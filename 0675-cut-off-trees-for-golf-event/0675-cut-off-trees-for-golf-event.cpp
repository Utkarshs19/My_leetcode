class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        
        priority_queue<int,vector<int>,greater<int>> pq;

        int n=forest.size();
        int m=forest[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(forest[i][j]>1)pq.push(forest[i][j]);
            }
        }

        int ans=0;
        int x=0,y=0;
        int cnt=0;
        while(!pq.empty())
        {
            queue<pair<pair<int,int>,int>> q;
            q.push({{x,y},0});
            vector<vector<int>> vis(n,vector<int>(m,0));
            vis[x][y]=1;
            bool flag=false;
            while(!q.empty())
            {
                int size=q.size();
                if(flag)break;
                for(int i=0;i<size;i++)
                {
                    int a=q.front().first.first;
                    int b=q.front().first.second;
                    int c=q.front().second;
                    q.pop();

                    if(forest[a][b]==pq.top())
                    {
                        x=a;
                        y=b;
                        ans+=c;
                        pq.pop();
                        flag=true;
                        break;
                    }
                    
                    if(a-1>=0 && forest[a-1][b]!=0 && !vis[a-1][b]){
                        vis[a-1][b]=1;
                        q.push({{a-1,b},c+1});
                        }
                    if(a+1<n && forest[a+1][b]!=0 && !vis[a+1][b])
                    {
                        vis[a+1][b]=1;
                        q.push({{a+1,b},c+1});
                    }
                    if(b-1>=0 && forest[a][b-1]!=0 && !vis[a][b-1])
                    {
                        vis[a][b-1]=1;
                        q.push({{a,b-1},c+1});
                    }
                    if(b+1<m && forest[a][b+1]!=0 && !vis[a][b+1])
                    {
                        vis[a][b+1]=1;
                        q.push({{a,b+1},c+1});
                    }
                }
            }
            if(!flag)return -1;
        }

        return ans;

    }
};