class Solution {
public:
    int minJumps(vector<int>& arr) {

        map<int,vector<int>> m;

        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
        }
        int n=arr.size();
        queue<int> q;
        vector<int> vis(n,0);
        
        q.push(0);
        vis[0]=1;
        int ans=0;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int idx=q.front();
                q.pop();
                if(idx==n-1)return ans;

                if(idx+1<n && !vis[idx+1])
                {
                    vis[idx+1]=1;
                    q.push(idx+1);
                }
                if(idx-1>=0 && !vis[idx-1])
                {
                    vis[idx-1]=1;
                    q.push(idx-1);
                }

                for(auto j:m[arr[idx]])
                {
                    if(!vis[j])
                    {
                        vis[j]=1;
                        q.push(j);
                    }
                }
                m[arr[idx]].clear();
            }
            ans++;
        }

        return ans;
    }
};