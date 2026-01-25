class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        long long  ans=0;
        int n=status.size();
        vector<int> vis(n,0);
        set<int> k;
        queue<int> q;
        
        set<int> st;
        for(int i=0;i<initialBoxes.size();i++)
        {
            if(status[initialBoxes[i]]==1){
                vis[initialBoxes[i]]=1;
            q.push(initialBoxes[i]);}
            else
            st.insert(initialBoxes[i]);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans+=candies[x];

            for(auto i:keys[x])
            {
                k.insert(i);
                if(st.count(i) && !vis[i])
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
                    if(k.count(i) && !vis[i])
                    {
                        vis[i]=1;
                        q.push(i);
                    }
                    else
                    {
                        st.insert(i);
                    }
                }
            }
        }
        return ans;
    }
};