class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        long long  ans=0;
        int n=status.size();
        vector<int> vis(n,0);
        vector<int> k(n,0);
        queue<int> q;
        
        vector<int> st(n,0);
        for(int i=0;i<initialBoxes.size();i++)
        {
            if(status[initialBoxes[i]]==1){
                vis[initialBoxes[i]]=1;
            q.push(initialBoxes[i]);}
            else
            st[initialBoxes[i]]=1;
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans+=candies[x];

            for(auto i:keys[x])
            {
                k[i]=1;
                if(st[i] && !vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
            }

            for(auto i:containedBoxes[x])
            {
                if(status[i]==1 && !vis[i])
                {
                    vis[i]=1;
                    q.push(i);

                }
                else
                {
                    if(k[i] && !vis[i])
                    {
                        vis[i]=1;
                        q.push(i);
                    }
                    else
                    {
                        st[i]=1;
                    }
                }
            }
        }
        return ans;
    }
};