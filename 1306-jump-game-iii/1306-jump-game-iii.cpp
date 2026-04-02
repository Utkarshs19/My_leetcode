class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n=arr.size();

        vector<int> vis(n,0);
        queue<int> q;
        q.push(start);
        vis[start]=1;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front();
                q.pop();

                if(arr[x]==0)return true;
                
                if(x-arr[x]>=0 && !vis[x-arr[x]]){
                    vis[x-arr[x]]=1;
                    q.push(x-arr[x]);
                }
                if(x+arr[x]<n && !vis[x+arr[x]]){
                    vis[x+arr[x]]=1;
                    q.push(x+arr[x]);
                }

            }
        }
        return false;
    }
};